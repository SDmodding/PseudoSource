// File Line: 13
// RVA: 0x13017D0
hkTrackerScanSnapshot *__fastcall makeSnapshot(hkTrackerSnapshot *snapshot)
{
  hkResult result; // [rsp+38h] [rbp+10h] BYREF

  hkTrackerSnapshot::init(snapshot, &result, 0i64, 0i64);
  return hkTrackerSnapshotUtil::createSnapshot(snapshot, 0i64);
}

// File Line: 22
// RVA: 0x1301680
hkTrackerScanSnapshot *__fastcall hkTrackerSnapshotUtil::createSnapshot()
{
  hkTrackerScanSnapshot *v0; // rbx
  hkTrackerSnapshot snapshot; // [rsp+20h] [rbp-98h] BYREF

  hkTrackerSnapshot::hkTrackerSnapshot(&snapshot);
  v0 = makeSnapshot(&snapshot);
  hkTrackerSnapshot::~hkTrackerSnapshot(&snapshot);
  return v0;
}

// File Line: 28
// RVA: 0x13016C0
hkTrackerScanSnapshot *__fastcall hkTrackerSnapshotUtil::createSnapshot(hkMemoryAllocator *mem)
{
  hkTrackerScanSnapshot *v1; // rbx
  hkTrackerSnapshot snapshot; // [rsp+20h] [rbp-98h] BYREF

  hkTrackerSnapshot::hkTrackerSnapshot(&snapshot, mem);
  v1 = makeSnapshot(&snapshot);
  hkTrackerSnapshot::~hkTrackerSnapshot(&snapshot);
  return v1;
}

// File Line: 34
// RVA: 0x1301700
hkTrackerScanSnapshot *__fastcall hkTrackerSnapshotUtil::createSnapshot(
        hkTrackerSnapshot *snapshot,
        hkTrackerLayoutCalculator *layoutCalc)
{
  _QWORD **Value; // rax
  hkTrackerTypeTreeCache *v4; // rax
  hkTrackerLayoutCalculator *v5; // rdi
  hkTrackerTypeTreeCache *v6; // rax
  hkTrackerTypeTreeCache *v7; // rbx
  _QWORD **v8; // rax
  hkTrackerLayoutCalculator *v9; // rax
  hkTrackerLayoutCalculator *v10; // rax
  hkTrackerScanSnapshot *v11; // rbx
  hkTrackerScanCalculator v13; // [rsp+38h] [rbp+10h] BYREF

  if ( layoutCalc )
    return hkTrackerScanCalculator::createSnapshot(&v13, snapshot, layoutCalc);
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v4 = (hkTrackerTypeTreeCache *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 368i64);
  v5 = 0i64;
  if ( v4 )
  {
    hkTrackerTypeTreeCache::hkTrackerTypeTreeCache(v4);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkTrackerLayoutCalculator *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v8[11] + 8i64))(v8[11], 96i64);
  if ( v9 )
  {
    hkTrackerLayoutCalculator::hkTrackerLayoutCalculator(v9, v7);
    v5 = v10;
  }
  hkReferencedObject::removeReference(v7);
  v11 = hkTrackerScanCalculator::createSnapshot(&v13, snapshot, v5);
  hkReferencedObject::removeReference(v5);
  return v11;
}

