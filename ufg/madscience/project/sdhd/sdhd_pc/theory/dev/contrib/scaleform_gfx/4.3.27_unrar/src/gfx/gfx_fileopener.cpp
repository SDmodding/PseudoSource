// File Line: 28
// RVA: 0x8EEC10
Scaleform::File *__fastcall Scaleform::GFx::FileOpener::OpenFile(
        Scaleform::GFx::FileOpener *this,
        const char *purl,
        int flags,
        int modes)
{
  char v7; // bl
  Scaleform::SysFile *v8; // rdi
  __int64 v9; // rax
  __int64 v10; // rdi
  Scaleform::String path; // [rsp+28h] [rbp-20h] BYREF
  __int64 v13; // [rsp+30h] [rbp-18h]
  Scaleform::SysFile *v14; // [rsp+38h] [rbp-10h]

  v13 = -2i64;
  v7 = 0;
  v8 = (Scaleform::SysFile *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(Scaleform::Memory::pGlobalHeap, 24i64, 0i64);
  v14 = v8;
  if ( v8 )
  {
    Scaleform::String::String(&path, purl);
    v7 = 1;
    Scaleform::SysFile::SysFile(v8, &path, flags, modes);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  if ( (v7 & 1) != 0
    && !_InterlockedDecrement((volatile signed __int32 *)((path.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
  {
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
  return (Scaleform::File *)v10;
}

// File Line: 34
// RVA: 0x8D7A90
__int64 __fastcall Scaleform::GFx::FileOpener::GetFileModifyTime(Scaleform::GFx::FileOpener *this, const char *purl)
{
  bool FileStat; // di
  __int64 v3; // rbx
  Scaleform::FileStat pfileStat; // [rsp+28h] [rbp-20h] BYREF
  Scaleform::String path; // [rsp+60h] [rbp+18h] BYREF

  Scaleform::String::String(&path, purl);
  FileStat = Scaleform::SysFile::GetFileStat(&pfileStat, &path);
  v3 = -1i64;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((path.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( FileStat )
    return pfileStat.ModifyTime;
  return v3;
}

// File Line: 45
// RVA: 0x8EED80
Scaleform::Render::RenderBuffer *__fastcall Scaleform::GFx::FileOpener::OpenFileEx(
        Scaleform::GFx::FileOpener *this,
        const char *pfilename,
        Scaleform::Log *plog,
        unsigned int flags,
        unsigned int modes)
{
  __int64 v7; // rax
  Scaleform::Render::RenderBuffer *v8; // rbx

  v7 = ((__int64 (__fastcall *)(Scaleform::GFx::FileOpener *, const char *, _QWORD, _QWORD))this->vfptr[1].__vecDelDtor)(
         this,
         pfilename,
         flags,
         modes);
  v8 = (Scaleform::Render::RenderBuffer *)v7;
  if ( v7 && !(*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v7 + 64i64))(v7) )
    return v8;
  if ( plog )
    Scaleform::Log::LogError(plog, "Loader failed to open %s", pfilename);
  if ( v8 )
    Scaleform::RefCountImpl::Release(v8);
  return 0i64;
}

