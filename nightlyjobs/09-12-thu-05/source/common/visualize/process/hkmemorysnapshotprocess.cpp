// File Line: 21
// RVA: 0xE78B80
void hkMemorySnapshotProcess::registerProcess(void)
{
  hkMemorySnapshotProcess::m_tag = hkProcessFactory::registerProcess(
                                     hkSingleton<hkProcessFactory>::s_instance,
                                     "* Grab Memory Snapshot",
                                     hkMemorySnapshotProcess::create);
}

// File Line: 26
// RVA: 0xE78B20
hkProcess *__fastcall hkMemorySnapshotProcess::create(hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkArray<hkProcessContext *,hkContainerHeapAllocator> *v1; // rbx
  _QWORD **v2; // rax
  hkMemorySnapshotProcess *v3; // rax
  __int64 v4; // rax
  hkProcess *result; // rax

  v1 = contexts;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkMemorySnapshotProcess *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 64i64);
  if ( v3 && (hkMemorySnapshotProcess::hkMemorySnapshotProcess(v3, v1), v4) )
    result = (hkProcess *)(v4 + 16);
  else
    result = 0i64;
  return result;
}

// File Line: 32
// RVA: 0xE78C60
void __fastcall hkMemorySnapshotProcess::hkMemorySnapshotProcess(hkMemorySnapshotProcess *this, hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_selectable.m_bool = 1;
  this->vfptr = (hkBaseObjectVtbl *)&hkMemorySnapshotProcess::`vftable{for `hkReferencedObject};
  this->vfptr = (hkProcessVtbl *)&hkMemorySnapshotProcess::`vftable{for `hkProcess};
}

// File Line: 37
// RVA: 0xE78BB0
void __fastcall hkMemorySnapshotProcess::step(hkMemorySnapshotProcess *this, float frameTimeInMs)
{
  hkMemorySnapshotProcess *v2; // rdi
  hkOArchive *v3; // rcx
  hkStreamWriter *v4; // rax
  hkTrackerScanSnapshot *v5; // rbx
  hkDisplaySerializeOStream *v6; // rcx
  hkOstream stream; // [rsp+20h] [rbp-58h]
  hkVdbCommandWriter v8; // [rsp+38h] [rbp-40h]
  char v9; // [rsp+80h] [rbp+8h]

  v2 = this;
  v3 = *(hkOArchive **)&this->m_selectable.m_bool;
  if ( v3 )
  {
    v4 = hkOArchive::getStreamWriter(v3);
    hkVdbCommandWriter::hkVdbCommandWriter(&v8, v4, 209, 0x800u);
    hkOstream::hkOstream(&stream, (hkStreamWriter *)&v8.vfptr);
    v5 = hkTrackerSnapshotUtil::createSnapshot();
    hkVdbStreamReportUtil::generateReport(v5, &stream);
    hkReferencedObject::removeReference((hkReferencedObject *)&v5->vfptr);
    hkOstream::~hkOstream(&stream);
    hkVdbCommandWriter::~hkVdbCommandWriter(&v8);
  }
  v6 = v2->m_outStream;
  if ( v6 )
    ((void (__fastcall *)(hkDisplaySerializeOStream *, char *, _QWORD))v6->vfptr[4].__vecDelDtor)(
      v6,
      &v9,
      (unsigned int)hkMemorySnapshotProcess::m_tag);
}

