// ============ KNAPSACK.C ================

// ================= Include =================

#include "knapsack.h"
#if BUILDMODE == 0
#include "knapsack-inline.c"
#endif

// ---- KnapSackPod

// ================ Functions implementation ====================

// Create a new KnapSackPod with id 'id', cost 'cost' and value 'val'
KnapSackPod* KnapSackPodCreate(int id, int cost, int val) {
#if BUILDMODE == 0
  if (cost <= 0) {
    GSetErr->_type = PBErrTypeInvalidArg;
    sprintf(GSetErr->_msg, "'cost' is invalid (0<%d)", cost);
    PBErrCatch(GSetErr);
  }
  if (val <= 0) {
    GSetErr->_type = PBErrTypeInvalidArg;
    sprintf(GSetErr->_msg, "'val' is invalid (0<%d)", val);
    PBErrCatch(GSetErr);
  }
#endif 
  // Declare the new pod
  KnapSackPod* pod = PBErrMalloc(KnapSackErr, sizeof(KnapSackPod));
  // Set properties
  pod->_id = id;
  pod->_cost = cost;
  pod->_val = val;
  // Return the new pod
  return pod;
}

// Free the memory used by the KnapSackPod 'that'
void KnapSackPodFree(KnapSackPod** that) {
  // Check argument
  if (that == NULL || *that == NULL)
    // Nothing to do
    return;
  // Free memory
  free(*that);
  *that = NULL;
}

// ---- KnapSack

// ================ Define ====================

#define KSMAX(a,b) ((a)>(b)?(a):(b))

// ================ Functions implementation ====================

// Create a new KnapSack with the budget 'budget'
KnapSack* KnapSackCreate(int budget) {
#if BUILDMODE == 0
  if (budget < 0) {
    GSetErr->_type = PBErrTypeInvalidArg;
    sprintf(GSetErr->_msg, "'budget' is invalid (0<=%d)", budget);
    PBErrCatch(GSetErr);
  }
#endif 
  // Declare the new KnapSack
  KnapSack* that = PBErrMalloc(KnapSackErr, sizeof(KnapSack));
  // Set properties
  that->_pods = GSetKnapSackPodCreateStatic();
  that->_sel = GSetKnapSackPodCreateStatic();
  that->_budget = budget;
  // Return the new KnapSack
  return that;
}

// Free the memory used by the KnapSack 'that'
// The two GSetKnapSackPod are flushed but it's the responsibility 
// of the user to free each KnapSackPod 
void KnapSackFree(KnapSack** that) {
  // Check argument
  if (that == NULL || *that == NULL)
    // Nothing to do
    return;
  // Free memory
  GSetFlush(&((*that)->_pods));
  GSetFlush(&((*that)->_sel));
  free(*that);
  *that = NULL;
}

// Select the best pods of the KnapSack 'that'
// https://en.wikipedia.org/wiki/Knapsack_problem 
void KSSelect(KnapSack* that) {
#if BUILDMODE == 0
  if (that == NULL) {
    GSetErr->_type = PBErrTypeNullPointer;
    sprintf(GSetErr->_msg, "'that' is null");
    PBErrCatch(GSetErr);
  }
#endif 
  // Flush the selected set
  GSetFlush(KSSelectedPods(that));
  // If there is no budget or no selectable pods
  if (KSGetNbPod(that) <= 0 || KSGetBudget(that) <= 0)
    // Nothing to do
    return;
  // Declare an array to calculate the solution
  int b = KSGetBudget(that) + 1;
  int* m = PBErrMalloc(KnapSackErr, 
    sizeof(int) * (KSGetNbPod(that) + 1) * b);
  // Initialise the array  
  for (int cost = b; cost--;)
    m[cost] = 0;
  // Calculate values in the array
  for (int iPod = 1; iPod <= KSGetNbPod(that); ++iPod) {
    KnapSackPod* pod = KSGetPod(that, iPod - 1);
    for (int cost = 0; cost <= KSGetBudget(that); ++cost) {
      if (KSPGetCost(pod) > cost) {
        m[iPod * b + cost] = m[(iPod - 1) * b + cost];
      } else {
        m[iPod * b + cost] = 
          KSMAX(m[(iPod - 1) * b + cost],
            m[(iPod - 1) * b + cost - KSPGetCost(pod)] + 
            KSPGetValue(pod));
      }
    }
  }
  // Find the selected pods
  int iPod = KSGetNbPod(that);
  int cost = KSGetBudget(that);
  while (iPod > 0 && cost > 0) {
    if (m[iPod * b + cost] != m[(iPod - 1) * b + cost]) {
      KnapSackPod* pod = KSGetPod(that, iPod - 1);
      GSetPush(KSSelectedPods(that), pod);
      cost -= KSPGetCost(pod);
    }
    --iPod;
  }
  // Free memory
  free(m);
}

// Get the cost of the KnapSack 'that' for currently selected pods
int KSGetCost(KnapSack* that) {
#if BUILDMODE == 0
  if (that == NULL) {
    GSetErr->_type = PBErrTypeNullPointer;
    sprintf(GSetErr->_msg, "'that' is null");
    PBErrCatch(GSetErr);
  }
#endif 
  // Declare a variable to calculate the cost
  int cost = 0;
  // Loop on selected pods and sum the cost
  if (KSGetNbSelectedPod(that) > 0) {
    GSetIterForward iter = 
      GSetIterForwardCreateStatic(KSSelectedPods(that));
    do {
      KnapSackPod* pod = GSetIterGet(&iter);
      cost += KSPGetCost(pod);
    } while (GSetIterStep(&iter));
  }
  // Return the value
  return cost;
}

// Get the value of the KnapSack 'that' for currently selected pods
int KSGetValue(KnapSack* that) {
#if BUILDMODE == 0
  if (that == NULL) {
    GSetErr->_type = PBErrTypeNullPointer;
    sprintf(GSetErr->_msg, "'that' is null");
    PBErrCatch(GSetErr);
  }
#endif 
  // Declare a variable to calculate the value
  int val = 0;
  // Loop on selected pods and sum the value
  if (KSGetNbSelectedPod(that) > 0) {
    GSetIterForward iter = 
      GSetIterForwardCreateStatic(KSSelectedPods(that));
    do {
      KnapSackPod* pod = GSetIterGet(&iter);
      val += KSPGetValue(pod);
    } while (GSetIterStep(&iter));
  }
  // Return the value
  return val;
}

