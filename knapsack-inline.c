// ============ KNAPSACK-INLINE.C ================

// ---- KnapSackPod

// ================ Functions implementation ====================

// Get the id of the KnapSackPod 'that'
#if BUILDMODE != 0
inline
#endif 
int KSPGetId(const KnapSackPod* const that) {
#if BUILDMODE == 0
  if (that == NULL) {
    GSetErr->_type = PBErrTypeNullPointer;
    sprintf(GSetErr->_msg, "'that' is null");
    PBErrCatch(GSetErr);
  }
#endif
  return that->_id;
}

// Get the cost of the KnapSackPod 'that'
#if BUILDMODE != 0
inline
#endif 
int KSPGetCost(const KnapSackPod* const that) {
#if BUILDMODE == 0
  if (that == NULL) {
    GSetErr->_type = PBErrTypeNullPointer;
    sprintf(GSetErr->_msg, "'that' is null");
    PBErrCatch(GSetErr);
  }
#endif
  return that->_cost;
}

// Get the value of the KnapSackPod 'that'
#if BUILDMODE != 0
inline
#endif 
int KSPGetValue(const KnapSackPod* const that) {
#if BUILDMODE == 0
  if (that == NULL) {
    GSetErr->_type = PBErrTypeNullPointer;
    sprintf(GSetErr->_msg, "'that' is null");
    PBErrCatch(GSetErr);
  }
#endif
  return that->_val;
}

// Set the cost of the KnapSackPod 'that' to 'cost'
#if BUILDMODE != 0
inline
#endif 
void KSPSetCost(KnapSackPod* const that, const int cost) {
#if BUILDMODE == 0
  if (that == NULL) {
    GSetErr->_type = PBErrTypeNullPointer;
    sprintf(GSetErr->_msg, "'that' is null");
    PBErrCatch(GSetErr);
  }
  if (cost <= 0) {
    GSetErr->_type = PBErrTypeInvalidArg;
    sprintf(GSetErr->_msg, "'cost' is invalid (0<%d)", cost);
    PBErrCatch(GSetErr);
  }
#endif
  that->_cost = cost;
}

// Set the value of the KnapSackPod 'that' to 'val'
#if BUILDMODE != 0
inline
#endif 
void KSPSetValue(KnapSackPod* const that, const int val) {
#if BUILDMODE == 0
  if (that == NULL) {
    GSetErr->_type = PBErrTypeNullPointer;
    sprintf(GSetErr->_msg, "'that' is null");
    PBErrCatch(GSetErr);
  }
  if (val <= 0) {
    GSetErr->_type = PBErrTypeInvalidArg;
    sprintf(GSetErr->_msg, "'val' is invalid (0<%d)", val);
    PBErrCatch(GSetErr);
  }
#endif
  that->_val = val;
}

// ---- KnapSack

// ================ Functions implementation ====================

// Get the budget of the KnapSack 'that'
#if BUILDMODE != 0
inline
#endif 
int KSGetBudget(const KnapSack* const that) {
#if BUILDMODE == 0
  if (that == NULL) {
    GSetErr->_type = PBErrTypeNullPointer;
    sprintf(GSetErr->_msg, "'that' is null");
    PBErrCatch(GSetErr);
  }
#endif 
  return that->_budget;
}

// Set the budget of the KnapSack 'that'
#if BUILDMODE != 0
inline
#endif 
void KSSetBudget(KnapSack* const that, const int budget) {
#if BUILDMODE == 0
  if (that == NULL) {
    GSetErr->_type = PBErrTypeNullPointer;
    sprintf(GSetErr->_msg, "'that' is null");
    PBErrCatch(GSetErr);
  }
  if (budget < 0) {
    GSetErr->_type = PBErrTypeInvalidArg;
    sprintf(GSetErr->_msg, "'budget' is invalid (0<=%d)", budget);
    PBErrCatch(GSetErr);
  }
#endif 
  that->_budget = budget;
}

// Get the GSet of selectable KnapSackPod of the KnapSack 'that'
#if BUILDMODE != 0
inline
#endif 
GSetKnapSackPod* KSPods(const KnapSack* const that) {
#if BUILDMODE == 0
  if (that == NULL) {
    GSetErr->_type = PBErrTypeNullPointer;
    sprintf(GSetErr->_msg, "'that' is null");
    PBErrCatch(GSetErr);
  }
#endif 
  return (GSetKnapSackPod*)&(that->_pods);
}

// Get the GSet of selected KnapSackPod of the KnapSack 'that'
#if BUILDMODE != 0
inline
#endif 
GSetKnapSackPod* KSSelectedPods(const KnapSack* const that) {
#if BUILDMODE == 0
  if (that == NULL) {
    GSetErr->_type = PBErrTypeNullPointer;
    sprintf(GSetErr->_msg, "'that' is null");
    PBErrCatch(GSetErr);
  }
#endif 
  return (GSetKnapSackPod*)&(that->_sel);
}

// Get the 'iPod'-th KnapSackPod of selectable pods of the 
// KnapSack 'that'
#if BUILDMODE != 0
inline
#endif 
KnapSackPod* KSGetPod(const KnapSack* const that, const int iPod) {
#if BUILDMODE == 0
  if (that == NULL) {
    GSetErr->_type = PBErrTypeNullPointer;
    sprintf(GSetErr->_msg, "'that' is null");
    PBErrCatch(GSetErr);
  }
  if (iPod < 0) {
    GSetErr->_type = PBErrTypeInvalidArg;
    sprintf(GSetErr->_msg, "'iPod' is invalid (0<=%d)", iPod);
    PBErrCatch(GSetErr);
  }
#endif 
  return GSetGet(KSPods(that), iPod);
}

// Get the number of selectable pods of the KnapSack 'that'
#if BUILDMODE != 0
inline
#endif 
int KSGetNbPod(const KnapSack* const that) {
#if BUILDMODE == 0
  if (that == NULL) {
    GSetErr->_type = PBErrTypeNullPointer;
    sprintf(GSetErr->_msg, "'that' is null");
    PBErrCatch(GSetErr);
  }
#endif 
  return GSetNbElem(KSPods(that));
}

// Get the 'iPod'-th KnapSackPod of selected pods of the 
// KnapSack 'that'
#if BUILDMODE != 0
inline
#endif 
KnapSackPod* KSGetSelectedPod(const KnapSack* const that, const int iPod) {
#if BUILDMODE == 0
  if (that == NULL) {
    GSetErr->_type = PBErrTypeNullPointer;
    sprintf(GSetErr->_msg, "'that' is null");
    PBErrCatch(GSetErr);
  }
  if (iPod < 0) {
    GSetErr->_type = PBErrTypeInvalidArg;
    sprintf(GSetErr->_msg, "'iPod' is invalid (0<=%d)", iPod);
    PBErrCatch(GSetErr);
  }
#endif 
  return GSetGet(KSSelectedPods(that), iPod);
}

// Get the number of selected pods of the KnapSack 'that'
#if BUILDMODE != 0
inline
#endif 
int KSGetNbSelectedPod(const KnapSack* const that) {
#if BUILDMODE == 0
  if (that == NULL) {
    GSetErr->_type = PBErrTypeNullPointer;
    sprintf(GSetErr->_msg, "'that' is null");
    PBErrCatch(GSetErr);
  }
#endif 
  return GSetNbElem(KSSelectedPods(that));
}

