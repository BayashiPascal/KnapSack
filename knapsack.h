// ============ KNAPSACK.H ================

#ifndef KNAPSACK_H
#define KNAPSACK_H

// ================= Include =================

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "pberr.h"
#include "gset.h"

// ---- KnapSackPod

// ================= Data structure ===================

typedef struct KnapSackPod {
  // ID
  int _id;
  // Cost
  int _cost;
  // Value
  int _val;
} KnapSackPod;

// ================ Functions declaration ====================

// Create a new KnapSackPod with id 'id', cost 'cost' and value 'val'
KnapSackPod* KnapSackPodCreate(int id, int cost, int val);

// Free the memory used by the KnapSackPod 'that'
void KnapSackPodFree(KnapSackPod** that);

// Get the id of the KnapSackPod 'that'
#if BUILDMODE != 0
inline
#endif 
int KSPGetId(KnapSackPod* that);

// Get the cost of the KnapSackPod 'that'
#if BUILDMODE != 0
inline
#endif 
int KSPGetCost(KnapSackPod* that);

// Get the value of the KnapSackPod 'that'
#if BUILDMODE != 0
inline
#endif 
int KSPGetValue(KnapSackPod* that);

// Set the cost of the KnapSackPod 'that' to 'cost'
#if BUILDMODE != 0
inline
#endif 
void KSPSetCost(KnapSackPod* that, int cost);

// Set the value of the KnapSackPod 'that' to 'val'
#if BUILDMODE != 0
inline
#endif 
void KSPSetValue(KnapSackPod* that, int val);

// ---- 0-1 KnapSack

// ================= Data structure ===================

typedef struct KnapSack {
  // Budget
  int _budget;
  // GSet of selectable KnapSackPod
  GSetKnapSackPod _pods;
  // GSet of selected KnapSackPod
  GSetKnapSackPod _sel;
} KnapSack;

// ================ Functions declaration ====================

// Create a new KnapSack with the budget 'budget'
KnapSack* KnapSackCreate(int budget);

// Free the memory used by the KnapSack 'that'
// The two GSetKnapSackPod are flushed but it's the responsibility 
// of the user to free each KnapSackPod 
void KnapSackFree(KnapSack** that);

// Get the budget of the KnapSack 'that'
#if BUILDMODE != 0
inline
#endif 
int KSGetBudget(KnapSack* that);

// Set the budget of the KnapSack 'that'
#if BUILDMODE != 0
inline
#endif 
void KSSetBudget(KnapSack* that, int budget);

// Get the GSet of selectable KnapSackPod of the KnapSack 'that'
#if BUILDMODE != 0
inline
#endif 
GSetKnapSackPod* KSPods(KnapSack* that);

// Select the best pods of the KnapSack 'that'
// https://en.wikipedia.org/wiki/Knapsack_problem 
void KSSelect(KnapSack* that);

// Get the GSet of selected KnapSackPod of the KnapSack 'that'
#if BUILDMODE != 0
inline
#endif 
GSetKnapSackPod* KSSelectedPods(KnapSack* that);

// Get the 'iPod'-th KnapSackPod of selectable pods of the 
// KnapSack 'that'
#if BUILDMODE != 0
inline
#endif 
KnapSackPod* KSGetPod(KnapSack* that, int iPod);

// Get the number of selectable pods of the KnapSack 'that'
#if BUILDMODE != 0
inline
#endif 
int KSGetNbPod(KnapSack* that);

// Get the 'iPod'-th KnapSackPod of selected pods of the 
// KnapSack 'that'
#if BUILDMODE != 0
inline
#endif 
KnapSackPod* KSGetSelectedPod(KnapSack* that, int iPod);

// Get the number of selected pods of the KnapSack 'that'
#if BUILDMODE != 0
inline
#endif 
int KSGetNbSelectedPod(KnapSack* that);

// Get the cost of the KnapSack 'that' for currently selected pods
int KSGetCost(KnapSack* that);

// Get the value of the KnapSack 'that' for currently selected pods
int KSGetValue(KnapSack* that);

// ================ Inliner ====================

#if BUILDMODE != 0
#include "knapsack-inline.c"
#endif


#endif
