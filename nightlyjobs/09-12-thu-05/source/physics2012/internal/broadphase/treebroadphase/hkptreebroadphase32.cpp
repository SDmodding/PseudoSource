// File Line: 17
// RVA: 0xDA6C80
void __fastcall hkpTreeBroadPhase32_createTreeBroadPhase(hkpBroadPhase *childBroadPhase)
{
  hkpBroadPhase *v1; // rbx
  _QWORD **v2; // rax
  hkpTreeBroadPhase32 *v3; // rax

  v1 = childBroadPhase;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkpTreeBroadPhase32 *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 416i64);
  if ( v3 )
    hkpTreeBroadPhase32::hkpTreeBroadPhase32(v3, v1);
}

// File Line: 22
// RVA: 0xDAC9F0
void __fastcall hkpTreeBroadPhase32_updateTreeBroadPhase(hkpBroadPhase *broadPhase, float physicsDeltaStep)
{
  hkpTreeBroadPhase32::update((hkpTreeBroadPhase32 *)broadPhase, physicsDeltaStep);
}

// File Line: 28
// RVA: 0xDACA00
void (__fastcall *hkpTreeBroadPhase32_registerSelf())(hkpBroadPhase *broadPhase, float physicsDeltaStep)
{
  void (__fastcall *result)(hkpBroadPhase *, float); // rax

  result = hkpTreeBroadPhase32_updateTreeBroadPhase;
  hkpBroadPhase::s_updateTreeBroadPhaseFunction32 = hkpTreeBroadPhase32_updateTreeBroadPhase;
  return result;
}

// File Line: 32
// RVA: 0x15D2A30
void dynamic_initializer_for__hkOptionalComponent_hkpTreeBroadPhase32__()
{
  hkOptionalComponent::hkOptionalComponent(
    &hkOptionalComponent_hkpTreeBroadPhase32,
    "hkpTreeBroadPhase32",
    (void (__fastcall *)())hkpTreeBroadPhase32_registerSelf);
}

