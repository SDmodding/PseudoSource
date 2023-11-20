// File Line: 28
// RVA: 0x8EEC10
Scaleform::File *__fastcall Scaleform::GFx::FileOpener::OpenFile(Scaleform::GFx::FileOpener *this, const char *purl, int flags, int modes)
{
  int v4; // esi
  int v5; // ebp
  const char *v6; // r14
  char v7; // bl
  Scaleform::SysFile *v8; // rdi
  __int64 v9; // rax
  __int64 v10; // rdi
  Scaleform::String path; // [rsp+28h] [rbp-20h]
  __int64 v13; // [rsp+30h] [rbp-18h]
  Scaleform::SysFile *v14; // [rsp+38h] [rbp-10h]

  v13 = -2i64;
  v4 = modes;
  v5 = flags;
  v6 = purl;
  v7 = 0;
  v8 = (Scaleform::SysFile *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(Scaleform::Memory::pGlobalHeap, 24ui64, 0i64);
  v14 = v8;
  if ( v8 )
  {
    Scaleform::String::String(&path, v6);
    v7 = 1;
    Scaleform::SysFile::SysFile(v8, &path, v5, v4);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  if ( v7 & 1 && !_InterlockedDecrement((volatile signed __int32 *)((path.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  return (Scaleform::File *)v10;
}

// File Line: 34
// RVA: 0x8D7A90
__int64 __fastcall Scaleform::GFx::FileOpener::GetFileModifyTime(Scaleform::GFx::FileOpener *this, const char *purl)
{
  bool v2; // di
  __int64 v3; // rbx
  Scaleform::FileStat pfileStat; // [rsp+28h] [rbp-20h]
  Scaleform::String path; // [rsp+60h] [rbp+18h]

  Scaleform::String::String(&path, purl);
  v2 = Scaleform::SysFile::GetFileStat(&pfileStat, &path);
  v3 = -1i64;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((path.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( v2 )
    v3 = pfileStat.ModifyTime;
  return v3;
}

// File Line: 45
// RVA: 0x8EED80
Scaleform::Render::RenderBuffer *__fastcall Scaleform::GFx::FileOpener::OpenFileEx(Scaleform::GFx::FileOpener *this, const char *pfilename, Scaleform::Log *plog, int flags, int modes)
{
  Scaleform::Log *v5; // rdi
  const char *v6; // rsi
  __int64 v7; // rax
  Scaleform::Render::RenderBuffer *v8; // rbx

  v5 = plog;
  v6 = pfilename;
  v7 = ((__int64 (__fastcall *)(Scaleform::GFx::FileOpener *, const char *, _QWORD, _QWORD))this->vfptr[1].__vecDelDtor)(
         this,
         pfilename,
         (unsigned int)flags,
         (unsigned int)modes);
  v8 = (Scaleform::Render::RenderBuffer *)v7;
  if ( v7 && !(*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v7 + 64i64))(v7) )
    return v8;
  if ( v5 )
    Scaleform::Log::LogError(v5, "Loader failed to open %s", v6);
  if ( v8 )
    Scaleform::RefCountImpl::Release(v8);
  return 0i64;
}

