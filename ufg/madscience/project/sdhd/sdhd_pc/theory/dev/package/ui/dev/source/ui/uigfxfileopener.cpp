// File Line: 95
// RVA: 0xA30500
void __fastcall UFG::UIGfxFileOpener::loadChunkFile(UFG::UIGfxFileOpener *this, const char *filename)
{
  char dest; // [rsp+30h] [rbp-208h]

  if ( this->mUsingChunkFiles )
  {
    UFG::qSPrintf(&dest, 512, "%s%s", UFG::UIScreenManager::s_instance->m_screenFactory->m_rootDir, filename);
    UFG::StreamResourceLoader::LoadResourceFile(&dest, &gScaleformMemoryPool, 1u, 0i64, 0i64, 0i64);
  }
}

// File Line: 116
// RVA: 0xA32460
void __fastcall UFG::UIGfxFileOpener::unloadChunkFile(UFG::UIGfxFileOpener *this, const char *filename)
{
  char dest; // [rsp+30h] [rbp-208h]

  if ( this->mUsingChunkFiles )
  {
    UFG::qSPrintf(&dest, 512, "%s%s", UFG::UIScreenManager::s_instance->m_screenFactory->m_rootDir, filename);
    UFG::StreamResourceLoader::UnloadResourceFile(&dest);
  }
}

// File Line: 151
// RVA: 0xA2AD60
void __fastcall UFG::fnUIGfxFileOpenerEntireFileCallback(const char *filename, void *data, int fileSize, void *param)
{
  if ( UFG::UIGfxFileOpener_GameExiting )
  {
    operator delete[](param);
  }
  else
  {
    *((_DWORD *)param + 1) = fileSize;
    *((_QWORD *)param + 1) = data;
    *(_WORD *)param = 257;
  }
}

// File Line: 179
// RVA: 0xA27CB0
Scaleform::File *__fastcall UFG::UIGfxFileOpener::OpenFile(UFG::UIGfxFileOpener *this, const char *_filename, __int64 flags, __int64 mode)
{
  UFG::qString *v4; // rax
  __int64 v5; // rdi
  UFG::qResourceWarehouse *v6; // rax
  UFG::qResourceData *v7; // rax
  UFG::qBaseNodeRB *v8; // rcx
  char *v9; // rbx
  unsigned int v10; // esi
  UFG::allocator::free_link *v11; // rbp
  UFG::UIGfxMemoryFile *v12; // rax
  __int64 v13; // rax
  UFG::allocator::free_link *v14; // rax
  UFG::allocator::free_link *v15; // rbx
  UFG *v16; // rcx
  UFG::allocator::free_link *v17; // rsi
  __int64 v18; // r14
  signed __int64 v19; // r14
  UFG::allocator::free_link *v20; // r15
  UFG::UIGfxMemoryFile *v21; // rax
  __int64 v22; // rax
  UFG::qString v24; // [rsp+48h] [rbp-B0h]
  UFG::qString text; // [rsp+70h] [rbp-88h]
  __int64 v26; // [rsp+98h] [rbp-60h]
  UFG::qString result; // [rsp+A0h] [rbp-58h]

  v26 = -2i64;
  UFG::qString::qString(&text, _filename, flags, mode);
  UFG::qString::ReplaceString(&text, ".gfx", ".bin", 0);
  UFG::qString::qString(&v24, &text);
  UFG::qString::MakeLower(&v24);
  v4 = UFG::qString::GetFilenameWithoutExtension(&v24, &result);
  v5 = 0i64;
  UFG::qString::Set(&v24, v4->mData, v4->mLength, 0i64, 0);
  UFG::qString::~qString(&result);
  if ( v24.mStringHashUpper32 == -1 )
    v24.mStringHashUpper32 = UFG::qStringHashUpper32(v24.mData, 0xFFFFFFFF);
  v6 = UFG::qResourceWarehouse::Instance();
  v7 = UFG::qResourceWarehouse::DebugGet(v6, 0x442A39D9u, v24.mStringHashUpper32);
  if ( v7 )
  {
    v8 = v7[1].mNode.mChild[0];
    if ( v8 )
      v9 = (char *)v7[1].mNode.mChild + (_QWORD)v8;
    else
      v9 = 0i64;
    v10 = (unsigned int)v7[1].mNode.mParent;
    v11 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, v10, "new_gfx_file", 0i64, 1u);
    UFG::qMemCopy(v11, v9, v10);
    v12 = (UFG::UIGfxMemoryFile *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                    Scaleform::Memory::pGlobalHeap,
                                    80i64);
    if ( v12 )
    {
      UFG::UIGfxMemoryFile::UIGfxMemoryFile(v12, text.mData, (const char *)v11, v10);
      v5 = v13;
    }
  }
  else
  {
    UFG::qPrintf("Could not find %s in the warehouse.  Loading it from disk...\n", v24.mData);
    v14 = UFG::qMalloc(0x10ui64, "Async::EntireFileRead", 0i64);
    v15 = v14;
    if ( v14 )
    {
      LOWORD(v14->mNext) = 0;
      HIDWORD(v14->mNext) = 0;
      v14[1].mNext = 0i64;
    }
    else
    {
      v15 = 0i64;
    }
    if ( UFG::StreamFileWrapper::ReadEntireFileAsync(
           text.mData,
           STREAM_DATA_HIGH_PRIORITY,
           UFG::fnUIGfxFileOpenerEntireFileCallback,
           v15,
           &gScaleformMemoryPool,
           0,
           "gfx_file") )
    {
      while ( !BYTE1(v15->mNext) )
      {
        if ( LOBYTE(v15->mNext) )
          break;
        if ( UFG::UIGfxFileOpener_GameExiting )
          goto LABEL_24;
        if ( GetCurrentThreadId() == UFG::sUIGfxFileOpener_ThreadID )
        {
          UFG::qFileService(v16);
          UFG::DataStreamer::Service(0.033333335);
          Render::StreamingLoopProcessQueuedOperations(1, 0);
        }
        UFG::qSleep(0xAu);
      }
      v17 = v15[1].mNext;
      v18 = SHIDWORD(v15->mNext);
      operator delete[](v15);
      if ( v17 )
      {
        v19 = v18 - 120;
        v20 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, v19, "new_gfx_file", 0i64, 1u);
        UFG::qMemCopy(v20, &v17[15], v19);
        UFG::qFreeEntireFile(v17, &gScaleformMemoryPool);
        v21 = (UFG::UIGfxMemoryFile *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                        Scaleform::Memory::pGlobalHeap,
                                        80i64);
        if ( v21 )
        {
          UFG::UIGfxMemoryFile::UIGfxMemoryFile(v21, text.mData, (const char *)v20, v19);
          v5 = v22;
        }
      }
    }
    else
    {
      operator delete[](v15);
    }
  }
LABEL_24:
  UFG::qString::~qString(&v24);
  UFG::qString::~qString(&text);
  return (Scaleform::File *)v5;
}

