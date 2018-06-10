#include <stdlib.h>
#include <stdio.h>
#include "pberr.h"
#include "knapsack.h"

void UnitTestKnapSackPodCreateFree() {
  KnapSackPod* pod = KnapSackPodCreate(1, 2, 3);
  if (pod == NULL ||
    pod->_id != 1 ||
    pod->_cost != 2 ||
    pod->_val != 3) {
    KnapSackErr->_type = PBErrTypeUnitTestFailed;
    sprintf(KnapSackErr->_msg, "KnapSackPodCreate failed");
    PBErrCatch(KnapSackErr);
  }
  KnapSackPodFree(&pod);
  if (pod != NULL) {
    KnapSackErr->_type = PBErrTypeUnitTestFailed;
    sprintf(KnapSackErr->_msg, "KnapSackPodFree failed");
    PBErrCatch(KnapSackErr);
  }
  printf("UnitTestKnapSackPodCreateFree OK\n");
}

void UnitTestKnapSackPodSetGet() {
  KnapSackPod* pod = KnapSackPodCreate(1, 2, 3);
  if (KSPGetCost(pod) != pod->_cost) {
    KnapSackErr->_type = PBErrTypeUnitTestFailed;
    sprintf(KnapSackErr->_msg, "KSGetCost failed");
    PBErrCatch(KnapSackErr);
  }
  KSPSetCost(pod, 4);
  if (KSPGetCost(pod) != 4) {
    KnapSackErr->_type = PBErrTypeUnitTestFailed;
    sprintf(KnapSackErr->_msg, "KSSetCost failed");
    PBErrCatch(KnapSackErr);
  }
  if (KSPGetValue(pod) != pod->_val) {
    KnapSackErr->_type = PBErrTypeUnitTestFailed;
    sprintf(KnapSackErr->_msg, "KSGetValue failed");
    PBErrCatch(KnapSackErr);
  }
  KSPSetValue(pod, 5);
  if (KSPGetValue(pod) != 5) {
    KnapSackErr->_type = PBErrTypeUnitTestFailed;
    sprintf(KnapSackErr->_msg, "KSSetValue failed");
    PBErrCatch(KnapSackErr);
  }
  if (KSPGetId(pod) != pod->_id) {
    KnapSackErr->_type = PBErrTypeUnitTestFailed;
    sprintf(KnapSackErr->_msg, "KSGetId failed");
    PBErrCatch(KnapSackErr);
  }
  KnapSackPodFree(&pod);
  printf("UnitTestKnapSackPodSetGet OK\n");
}

void UnitTestKnapSackPod() {
  UnitTestKnapSackPodCreateFree();
  UnitTestKnapSackPodSetGet();
  printf("UnitTestKnapSackPod OK\n");
}

void UnitTestKnapSackCreateFree() {
  KnapSack* ks = KnapSackCreate(1);
  if (ks == NULL ||
    ks->_budget != 1 ||
    GSetNbElem(&(ks->_pods)) != 0 ||
    GSetNbElem(&(ks->_sel)) != 0) {
    KnapSackErr->_type = PBErrTypeUnitTestFailed;
    sprintf(KnapSackErr->_msg, "KnapSackCreate failed");
    PBErrCatch(KnapSackErr);
  }
  KnapSackFree(&ks);
  if (ks != NULL) {
    KnapSackErr->_type = PBErrTypeUnitTestFailed;
    sprintf(KnapSackErr->_msg, "KnapSackFree failed");
    PBErrCatch(KnapSackErr);
  }
  printf("UnitTestKnapSackCreateFree OK\n");
}

void UnitTestKnapSackSetGet() {
  KnapSack* ks = KnapSackCreate(1);
  if (KSGetBudget(ks) != ks->_budget) {
    KnapSackErr->_type = PBErrTypeUnitTestFailed;
    sprintf(KnapSackErr->_msg, "KSGetBudget failed");
    PBErrCatch(KnapSackErr);
  }
  KSSetBudget(ks, 2);
  if (KSGetBudget(ks) != 2) {
    KnapSackErr->_type = PBErrTypeUnitTestFailed;
    sprintf(KnapSackErr->_msg, "KSSetBudget failed");
    PBErrCatch(KnapSackErr);
  }
  if (KSPods(ks) != &(ks->_pods)) {
    KnapSackErr->_type = PBErrTypeUnitTestFailed;
    sprintf(KnapSackErr->_msg, "KSPods failed");
    PBErrCatch(KnapSackErr);
  }
  if (KSSelectedPods(ks) != &(ks->_sel)) {
    KnapSackErr->_type = PBErrTypeUnitTestFailed;
    sprintf(KnapSackErr->_msg, "KSSelectedPods failed");
    PBErrCatch(KnapSackErr);
  }
  KnapSackPod* podA = KnapSackPodCreate(1, 2, 3);
  KnapSackPod* podB = KnapSackPodCreate(4, 5, 6);
  GSetAppend(KSPods(ks), podA);
  GSetAppend(KSPods(ks), podB);
  if (KSGetNbPod(ks) != 2) {
    KnapSackErr->_type = PBErrTypeUnitTestFailed;
    sprintf(KnapSackErr->_msg, "KSGetNbPod failed");
    PBErrCatch(KnapSackErr);
  }
  if (KSGetPod(ks, 0) != podA ||
    KSGetPod(ks, 1) != podB) {
    KnapSackErr->_type = PBErrTypeUnitTestFailed;
    sprintf(KnapSackErr->_msg, "KSGetPod failed");
    PBErrCatch(KnapSackErr);
  }
  GSetFlush(KSPods(ks));
  GSetAppend(KSSelectedPods(ks), podA);
  GSetAppend(KSSelectedPods(ks), podB);
  if (KSGetNbSelectedPod(ks) != 2) {
    KnapSackErr->_type = PBErrTypeUnitTestFailed;
    sprintf(KnapSackErr->_msg, "KSGetNbSelectedPod failed");
    PBErrCatch(KnapSackErr);
  }
  if (KSGetSelectedPod(ks, 0) != podA ||
    KSGetSelectedPod(ks, 1) != podB) {
    KnapSackErr->_type = PBErrTypeUnitTestFailed;
    sprintf(KnapSackErr->_msg, "KSGetSelectedPod failed");
    PBErrCatch(KnapSackErr);
  }
  GSetFlush(KSSelectedPods(ks));
  KnapSackPodFree(&podA);
  KnapSackPodFree(&podB);
  KnapSackFree(&ks);
  printf("UnitTestKnapSackSetGet OK\n");
}

void UnitTestKnapSackSelect() {
  KnapSack* ks = KnapSackCreate(15);
  int data[10] = {12, 4, 1, 2, 2, 2, 1, 1, 4, 10};
  for (int i = 5; i--;)
    KSAdd(ks, data[2 * i], data[2 * i + 1]);
  KSSelect(ks);
  if (KSGetNbSelectedPod(ks) != 4) {
    KnapSackErr->_type = PBErrTypeUnitTestFailed;
    sprintf(KnapSackErr->_msg, "KSSelect failed");
    PBErrCatch(KnapSackErr);
  }
  int check[4] = {0, 1, 2, 3};
  for (int i = KSGetNbSelectedPod(ks); i--;)
    if (KSPGetId(KSGetSelectedPod(ks, i)) != check[i]) {
      KnapSackErr->_type = PBErrTypeUnitTestFailed;
      sprintf(KnapSackErr->_msg, "KSSelect failed");
      PBErrCatch(KnapSackErr);
    }
  if (KSGetCost(ks) != 8) {
    KnapSackErr->_type = PBErrTypeUnitTestFailed;
    sprintf(KnapSackErr->_msg, "KSGetCost failed");
    PBErrCatch(KnapSackErr);
  }
  if (KSGetValue(ks) != 15) {
    KnapSackErr->_type = PBErrTypeUnitTestFailed;
    sprintf(KnapSackErr->_msg, "KSGetValue failed");
    PBErrCatch(KnapSackErr);
  }
  KnapSackFree(&ks);
  printf("UnitTestKnapSackSelect OK\n");
}

void UnitTestKnapSack() {
  UnitTestKnapSackCreateFree();
  UnitTestKnapSackSetGet();
  UnitTestKnapSackSelect();
  printf("UnitTestKnapSack OK\n");
}

void UnitTestAll() {
  UnitTestKnapSackPod();
  UnitTestKnapSack();
  printf("UnitTestAll OK\n");
}

int main() {
  UnitTestAll();
  // Return success code
  return 0;
}

