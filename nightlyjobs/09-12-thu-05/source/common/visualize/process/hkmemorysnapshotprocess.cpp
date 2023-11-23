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
  _QWORD **Value; // rax
  hkMemorySnapshotProcess *v3; // rax
  __int64 v4; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkMemorySnapshotProcess *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 64i64);
  if ( v3 && (hkMemorySnapshotProcess::hkMemorySnapshotProcess(v3, contexts), v4) )
    return (hkProcess *)(v4 + 16);
  else
    return 0i64;
}

// File Line: 32
// RVA: 0xE78C60
void __fastcall hkMemorySnapshotProcess::hkMemorySnapshotProcess(
        hkMemorySnapshotProcess *this,
        hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_selectable.m_bool = 1;
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkMemorySnapshotProcess::`vftable{for `hkReferencedObject};
  this->hkProcess::vfptr = (hkProcessVtbl *)&hkMemorySnapshotProcess::`vftable{for `hkProcess};
}

// File Line: 37
// RVA: 0xE78BB0
void __fastcall hkMemorySnapshotProcess::step(hkMemorySnapshotProcess *this, float frameTimeInMs)
{
  hkOArchive *v3; // rcx
  hkStreamWriter *StreamWriter; // rax
  hkTrackerScanSnapshot *Snapshot; // rbx
  hkDisplaySerializeOStream *m_outStream; // rcx
  hkOstream stream; // [rsp+20h] [rbp-58h] BYREF
  hkVdbCommandWriter v8; // [rsp+38h] [rbp-40h] BYREF
  char v9; // [rsp+80h] [rbp+8h] BYREF

  v3 = *(hkOArchive **)&this->m_selectable.m_bool;
  if ( v3 )
  {
    StreamWriter = hkOArchive::getStreamWriter(v3);
    hkVdbCommandWriter::hkVdbCommandWriter(&v8, StreamWriter, 209, 0x800u);
    hkOstream::hkOstream(&stream, &v8);
    Snapshot = hkTrackerSnapshotUtil::createSnapshot();
    hkVdbStreamReportUtil::generateReport(Snapshot, &stream);
    hkReferencedObject::removeReference(Snapshot);
    hkOstream::~hkOstream(&stream);
    hkVdbCommandWriter::~hkVdbCommandWriter(&v8);
  }
  m_outStream = this->m_outStream;
  if ( m_outStream )
    ((void (__fastcall *)(hkDisplaySerializeOStream *, char *, _QWORD))m_outStream->vfptr[4].__vecDelDtor)(
      m_outStream,
      &v9,
      (unsigned int)hkMemorySnapshotProcess::m_tag);
}

