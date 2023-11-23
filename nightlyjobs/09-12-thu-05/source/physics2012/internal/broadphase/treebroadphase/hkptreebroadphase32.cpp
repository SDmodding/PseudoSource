// File Line: 17
// RVA: 0xDA6C80
void __fastcall hkpTreeBroadPhase32_createTreeBroadPhase(hkpBroadPhase *childBroadPhase)
{
  _QWORD **Value; // rax
  hkpTreeBroadPhase32 *v3; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkpTreeBroadPhase32 *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 416i64);
  if ( v3 )
    hkpTreeBroadPhase32::hkpTreeBroadPhase32(v3, childBroadPhase);
}

// File Line: 22
// RVA: 0xDAC9F0
// attributes: thunk
void __fastcall hkpTreeBroadPhase32_updateTreeBroadPhase(hkpTreeBroadPhase32 *broadPhase, float physicsDeltaStep)
{
  hkpTreeBroadPhase32::update(broadPhase, physicsDeltaStep);
}

// File Line: 28
// RVA: 0xDACA00
void (__fastcall *hkpTreeBroadPhase32_registerSelf())(hkpTreeBroadPhase32 *broadPhase, float physicsDeltaStep)
{
  void (__fastcall *result)(hkpTreeBroadPhase32 *, float); // rax

  result = hkpTreeBroadPhase32_updateTreeBroadPhase;
  hkpBroadPhase::s_updateTreeBroadPhaseFunction32 = (void (__fastcall *)(hkpBroadPhase *, float))hkpTreeBroadPhase32_updateTreeBroadPhase;
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

