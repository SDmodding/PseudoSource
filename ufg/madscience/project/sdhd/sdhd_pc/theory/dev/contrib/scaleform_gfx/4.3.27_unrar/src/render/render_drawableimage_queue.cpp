// File Line: 37
// RVA: 0x98AF90
__int64 __fastcall Scaleform::Render::DICommand::GetRenderCaps(Scaleform::Render::DICommand *this)
{
  Scaleform::Render::DICommand *v1; // rdi
  unsigned int v2; // ebx
  Scaleform::Render::DrawableImage *v3; // rax
  Scaleform::Render::DrawableImageContext *v4; // rax
  Scaleform::Render::ThreadCommandQueue *v5; // rcx
  __int64 result; // rax
  __int64 v7; // [rsp+20h] [rbp-28h]
  __int128 v8; // [rsp+28h] [rbp-20h]
  __int64 v9; // [rsp+38h] [rbp-10h]

  v1 = this;
  v2 = ((__int64 (*)(void))this->vfptr->GetCPUCaps)();
  v3 = v1->pImage.pObject;
  if ( v3
    && (v4 = v3->pContext.pObject) != 0i64
    && (v5 = v4->pRTCommandQueue) != 0i64
    && (v7 = 0i64,
        v8 = 0ui64,
        v9 = 0i64,
        v5->vfptr->GetRenderInterfaces(v5, (Scaleform::Render::Interfaces *)&v7),
        (_QWORD)v8) )
  {
    result = v2 | (*(unsigned int (__fastcall **)(_QWORD, Scaleform::Render::DICommand *))(*(_QWORD *)v8 + 408i64))(
                    v8,
                    v1);
  }
  else
  {
    result = v2;
  }
  return result;
}

// File Line: 68
// RVA: 0x977CB0
char __fastcall Scaleform::Render::DICommand::ExecuteSWOnAddCommand(Scaleform::Render::DICommand *this, Scaleform::Render::DrawableImage *i)
{
  Scaleform::Render::DrawableImage *v2; // rsi
  Scaleform::Render::DICommand *v3; // r14
  char v4; // bp
  unsigned int imageCount; // er15
  unsigned int v7; // edi
  Scaleform::Render::DISourceImages *v8; // rbx
  Scaleform::Render::ThreadCommandQueue *v9; // rcx
  char v10; // bl
  Scaleform::Render::DISourceImages images; // [rsp+38h] [rbp-70h]
  Scaleform::Render::DICommandContext context; // [rsp+48h] [rbp-60h]
  __int64 v13; // [rsp+58h] [rbp-50h]
  Scaleform::Render::HAL *v14; // [rsp+60h] [rbp-48h]
  Scaleform::Render::Renderer2D *v15; // [rsp+68h] [rbp-40h]
  __int64 v16; // [rsp+70h] [rbp-38h]
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [rsp+B0h] [rbp+8h]

  v2 = i;
  v3 = this;
  v4 = ((__int64 (*)(void))this->vfptr->GetRenderCaps)();
  if ( !(v4 & 1) )
    return 0;
  images.pImages[0] = 0i64;
  images.pImages[1] = 0i64;
  imageCount = v3->vfptr->GetSourceImages(v3, &images);
  lpCriticalSection = &v2->pQueue.pObject->QueueLock.cs;
  EnterCriticalSection(lpCriticalSection);
  if ( v2->DrawableImageState & 3 && v2->RefCount <= 2 )
  {
    v7 = 0;
    v8 = &images;
    while ( !v8->pImages[0]
         || ((unsigned int (*)(void))v8->pImages[0]->vfptr[3].__vecDelDtor)() != 6
         || HIDWORD(v8->pImages[0][1].pUpdateSync) & 3 && v8->pImages[0]->RefCount <= 2 )
    {
      ++v7;
      v8 = (Scaleform::Render::DISourceImages *)((char *)v8 + 8);
      if ( v7 >= 2 )
      {
        v9 = v2->pContext.pObject->pRTCommandQueue;
        v13 = 0i64;
        v14 = 0i64;
        v15 = 0i64;
        v16 = 0i64;
        if ( v9 )
        {
          v9->vfptr->GetRenderInterfaces(v9, (Scaleform::Render::Interfaces *)&v13);
          context.pR2D = v15;
          context.pHAL = v14;
        }
        Scaleform::Render::DICommand::executeSWHelper(v3, &context, v2, &images, imageCount);
        if ( !(v4 & 0x20) )
          Scaleform::Render::DrawableImage::addToCPUModifiedList(v2);
        v10 = 1;
        goto LABEL_17;
      }
    }
  }
  v10 = 0;
LABEL_17:
  LeaveCriticalSection(lpCriticalSection);
  return v10;
}

// File Line: 125
// RVA: 0x9743C0
void __fastcall Scaleform::Render::DICommand::ExecuteRT(Scaleform::Render::DICommand *this, Scaleform::Render::DICommandContext *context)
{
  Scaleform::Render::DICommandContext *v2; // rsi
  Scaleform::Render::DICommand *v3; // rdi
  char v4; // al
  Scaleform::Render::DICommandQueue *v5; // rcx
  unsigned int imageCount; // ebp
  Scaleform::Render::DrawableImage *v7; // rbx
  unsigned int v8; // eax
  Scaleform::Render::DISourceImages images; // [rsp+30h] [rbp-18h]

  v2 = context;
  v3 = this;
  v4 = ((__int64 (*)(void))this->vfptr->GetRenderCaps)();
  v5 = v3->pImage.pObject->pQueue.pObject;
  if ( (v4 & 5) == 1 )
  {
    Scaleform::Render::DICommandQueue::updateGPUModifiedImagesRT(v5);
    images.pImages[0] = 0i64;
    images.pImages[1] = 0i64;
    imageCount = v3->vfptr->GetSourceImages(v3, &images);
    if ( v3->pImage.pObject->DrawableImageState & 3
      || (v7 = v3->pImage.pObject,
          v8 = v3->vfptr->GetRenderCaps(v3),
          Scaleform::Render::DrawableImage::mapTextureRT(v7, (v8 >> 5) & 1)) )
    {
      Scaleform::Render::DICommand::executeSWHelper(v3, v2, v3->pImage.pObject, &images, imageCount);
    }
  }
  else
  {
    Scaleform::Render::DICommandQueue::updateCPUModifiedImagesRT(v5);
    Scaleform::Render::DICommand::executeHWHelper(v3, v2, v3->pImage.pObject);
  }
}

// File Line: 160
// RVA: 0x9E2950
char __fastcall Scaleform::Render::DICommand::executeSWHelper(Scaleform::Render::DICommand *this, Scaleform::Render::DICommandContext *context, Scaleform::Render::DrawableImage *di, Scaleform::Render::DISourceImages *images, unsigned int imageCount)
{
  Scaleform::Render::DISourceImages *v5; // rsi
  Scaleform::Render::DrawableImage *v6; // rdi
  Scaleform::Render::DICommandContext *v7; // rbp
  Scaleform::Render::DICommand *v8; // rbx
  Scaleform::Render::ImageData *v9; // r14
  Scaleform::Render::ImageBase *v10; // rdx
  char *v12; // [rsp+30h] [rbp-B8h]
  Scaleform::Render::ImageData *v13; // [rsp+38h] [rbp-B0h]
  __int64 v14; // [rsp+40h] [rbp-A8h]
  char ptr; // [rsp+50h] [rbp-98h]
  Scaleform::Render::ImageData data; // [rsp+90h] [rbp-58h]

  v14 = -2i64;
  v5 = images;
  v6 = di;
  v7 = context;
  v8 = this;
  v9 = Scaleform::Render::DrawableImage::getMappedData(di);
  if ( imageCount )
  {
    `eh vector constructor iterator(
      &ptr,
      0x40ui64,
      2,
      (void (__fastcall *)(void *))Scaleform::Render::ImageData::ImageData);
    v12 = 0i64;
    v13 = 0i64;
    if ( v5->pImages[0]
      && !Scaleform::Render::DrawableImage::MapImageSource(
            (Scaleform::Render::ImageData *)&ptr,
            (Scaleform::Render::ImageBase *)&v5->pImages[0]->vfptr)
      || (v12 = &ptr, (v10 = (Scaleform::Render::ImageBase *)&v5->pImages[1]->vfptr) != 0i64)
      && !Scaleform::Render::DrawableImage::MapImageSource(&data, v10) )
    {
      `eh vector destructor iterator(
        &ptr,
        0x40ui64,
        2,
        (void (__fastcall *)(void *))Scaleform::Render::ImageData::~ImageData);
      return 0;
    }
    v13 = &data;
    ((void (__fastcall *)(Scaleform::Render::DICommand *, Scaleform::Render::DICommandContext *, Scaleform::Render::ImageData *, char **, void (__fastcall *)(Scaleform::Render::ImageData *)))v8->vfptr->ExecuteSW)(
      v8,
      v7,
      v9,
      &v12,
      Scaleform::Render::ImageData::~ImageData);
    `eh vector destructor iterator(
      &ptr,
      0x40ui64,
      2,
      (void (__fastcall *)(void *))Scaleform::Render::ImageData::~ImageData);
  }
  else
  {
    v8->vfptr->ExecuteSW(v8, v7, v9, 0i64);
  }
  if ( !(v8->vfptr->GetRenderCaps(v8) & 0x20) )
    Scaleform::Render::DrawableImage::addToCPUModifiedList(v6);
  return 1;
}

// File Line: 193
// RVA: 0x9E28B0
char __fastcall Scaleform::Render::DICommand::executeHWHelper(Scaleform::Render::DICommand *this, Scaleform::Render::DICommandContext *context, Scaleform::Render::DrawableImage *i)
{
  Scaleform::Render::DrawableImage *v3; // rbx
  Scaleform::Render::DICommandContext *v4; // rsi
  Scaleform::Render::DICommand *v5; // rdi
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [rsp+40h] [rbp+8h]

  v3 = i;
  v4 = context;
  v5 = this;
  lpCriticalSection = &i->pQueue.pObject->QueueLock.cs;
  EnterCriticalSection(lpCriticalSection);
  if ( v3->DrawableImageState & 3 && v3->pTexture.Value )
  {
    ((void (__cdecl *)(Scaleform::Render::Texture *volatile ))v3->pTexture.Value->vfptr[14].__vecDelDtor)(v3->pTexture.Value);
    v3->DrawableImageState &= 0xFFFFFFFC;
  }
  LeaveCriticalSection(lpCriticalSection);
  v5->vfptr->ExecuteHW(v5, v4);
  if ( (v5->vfptr->GetRenderCaps(v5) & 0xA) == 2 )
    Scaleform::Render::DrawableImage::addToGPUModifiedListRT(v3);
  return 1;
}

// File Line: 216
// RVA: 0x939BD0
void __fastcall Scaleform::Render::DICommandQueue::DICommandQueue(Scaleform::Render::DICommandQueue *this, Scaleform::Render::DrawableImageContext *dicontext)
{
  Scaleform::Render::DrawableImageContext *v2; // rbx
  Scaleform::Render::DICommandQueue *v3; // rdi
  Scaleform::Render::DICommandQueue::ExecuteCommand *v4; // rax
  Scaleform::Render::DICommandQueue::ExecuteCommand *v5; // rax
  Scaleform::List<Scaleform::Render::DIQueuePage,Scaleform::Render::DIQueuePage> *v6; // rcx

  v2 = dicontext;
  v3 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::DICommandQueue,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::DICommandQueue::`vftable;
  Scaleform::Mutex::Mutex(&this->CommandSetMutex, 1, 0);
  Scaleform::WaitCondition::WaitCondition(&v3->CommandSetWC);
  v3->pRTCommands = 0i64;
  v3->pCPUModifiedImageList.pObject = 0i64;
  v3->pGPUModifiedImageList.pObject = 0i64;
  v3->pRTCommandQueue = v2->pRTCommandQueue;
  Scaleform::Lock::Lock(&v3->QueueLock, 0);
  v4 = (Scaleform::Render::DICommandQueue::ExecuteCommand *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                                              Scaleform::Memory::pGlobalHeap,
                                                              112ui64,
                                                              0i64);
  if ( v4 )
    Scaleform::Render::DICommandQueue::ExecuteCommand::ExecuteCommand(v4, v3);
  else
    v5 = 0i64;
  v3->ExecuteCmd.pObject = v5;
  v6 = v3->Queues;
  v6->Root.pPrev = (Scaleform::Render::DIQueuePage *)v6;
  v6->Root.pNext = (Scaleform::Render::DIQueuePage *)v6;
  v3->Queues[1].Root.pPrev = (Scaleform::Render::DIQueuePage *)&v3->Queues[1];
  v6[1].Root.pNext = (Scaleform::Render::DIQueuePage *)&v3->Queues[1];
  v3->Queues[2].Root.pPrev = (Scaleform::Render::DIQueuePage *)&v3->Queues[2];
  v6[2].Root.pNext = (Scaleform::Render::DIQueuePage *)&v3->Queues[2];
  v3->Queues[3].Root.pPrev = (Scaleform::Render::DIQueuePage *)&v3->Queues[3];
  v6[3].Root.pNext = (Scaleform::Render::DIQueuePage *)&v3->Queues[3];
  *(_QWORD *)&v3->CaptureFrameId = 0i64;
  v3->AllocPageCount = 0;
}

// File Line: 220
// RVA: 0x949590
void __fastcall Scaleform::Render::DICommandQueue::~DICommandQueue(Scaleform::Render::DICommandQueue *this)
{
  Scaleform::Render::DICommandQueue *v1; // rdi
  _RTL_CRITICAL_SECTION *v2; // rbx
  Scaleform::Render::DIQueuePage *v3; // rdx
  Scaleform::Render::DICommandQueue::ExecuteCommand *v4; // rcx
  Scaleform::Render::DrawableImage *v5; // rcx
  Scaleform::Render::DrawableImage *v6; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::DICommandQueue::`vftable;
  v2 = &this->QueueLock.cs;
  EnterCriticalSection(&this->QueueLock.cs);
  while ( (Scaleform::List<Scaleform::Render::DIQueuePage,Scaleform::Render::DIQueuePage> *)v1->Queues[3].Root.pNext != &v1->Queues[3] )
  {
    v3 = v1->Queues[3].Root.pNext;
    v3->pPrev->pNext = v3->pNext;
    v3->pNext->pPrev = v3->pPrev;
    v3->pPrev = (Scaleform::Render::DIQueuePage *)-1i64;
    v3->pNext = (Scaleform::Render::DIQueuePage *)-1i64;
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
  LeaveCriticalSection(v2);
  v4 = v1->ExecuteCmd.pObject;
  if ( v4 && _InterlockedExchangeAdd(&v4->RefCount, 0xFFFFFFFF) == 1 && v4 )
    v4->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, 1u);
  DeleteCriticalSection(v2);
  v5 = v1->pGPUModifiedImageList.pObject;
  if ( v5 )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *))v5->vfptr[2].__vecDelDtor)(v5);
  v6 = v1->pCPUModifiedImageList.pObject;
  if ( v6 )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *))v6->vfptr[2].__vecDelDtor)(v6);
  Scaleform::WaitCondition::~WaitCondition(&v1->CommandSetWC);
  Scaleform::Mutex::~Mutex(&v1->CommandSetMutex);
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 239
// RVA: 0x9EBEB0
void __fastcall Scaleform::Render::DICommandQueue::popCommandSet(Scaleform::Render::DICommandQueue *this, Scaleform::Render::DICommandSet *cmdSet, Scaleform::Render::DICommandSetType type)
{
  Scaleform::Render::DICommandSetType v3; // ebp
  Scaleform::Render::DICommandSet *v4; // rdi
  Scaleform::Render::DICommandQueue *v5; // rsi
  Scaleform::Mutex *v6; // rbx
  Scaleform::List<Scaleform::Render::DIQueuePage,Scaleform::Render::DIQueuePage> *v7; // rax
  signed __int64 v8; // rdi
  Scaleform::Render::DIQueuePage *v9; // rdx
  Scaleform::Render::DIQueuePage *v10; // rcx
  Scaleform::List<Scaleform::Render::DIQueuePage,Scaleform::Render::DIQueuePage> *v11; // rax
  Scaleform::Render::DIQueuePage *v12; // rdx
  Scaleform::Render::DIQueuePage *v13; // rcx
  Scaleform::List<Scaleform::Render::DIQueuePage,Scaleform::Render::DIQueuePage> *v14; // rax
  Scaleform::Render::DIQueuePage *v15; // rdx
  Scaleform::Render::DIQueuePage *v16; // rcx

  v3 = type;
  v4 = cmdSet;
  v5 = this;
  v6 = &this->CommandSetMutex;
  Scaleform::Mutex::DoLock(&this->CommandSetMutex);
  v7 = &v5->Queues[2];
  v8 = (signed __int64)&v4->QueueList;
  v9 = v5->Queues[2].Root.pNext;
  if ( v9 != (Scaleform::Render::DIQueuePage *)&v5->Queues[2] )
  {
    v10 = v7->Root.pPrev;
    v7->Root.pPrev = (Scaleform::Render::DIQueuePage *)v7;
    v5->Queues[2].Root.pNext = (Scaleform::Render::DIQueuePage *)&v5->Queues[2];
    v10->pNext = (Scaleform::Render::DIQueuePage *)v8;
    v9->pPrev = *(Scaleform::Render::DIQueuePage **)v8;
    *(_QWORD *)(*(_QWORD *)v8 + 8i64) = v9;
    *(_QWORD *)v8 = v10;
  }
  if ( v3 == DICommand_All )
  {
    v11 = &v5->Queues[1];
    v12 = v5->Queues[1].Root.pNext;
    if ( v12 != (Scaleform::Render::DIQueuePage *)&v5->Queues[1] )
    {
      v13 = v11->Root.pPrev;
      v11->Root.pPrev = (Scaleform::Render::DIQueuePage *)v11;
      v5->Queues[1].Root.pNext = (Scaleform::Render::DIQueuePage *)&v5->Queues[1];
      v13->pNext = (Scaleform::Render::DIQueuePage *)v8;
      v12->pPrev = *(Scaleform::Render::DIQueuePage **)v8;
      *(_QWORD *)(*(_QWORD *)v8 + 8i64) = v12;
      *(_QWORD *)v8 = v13;
    }
    v14 = v5->Queues;
    v15 = v5->Queues[0].Root.pNext;
    if ( v15 != (Scaleform::Render::DIQueuePage *)v5->Queues )
    {
      v16 = v14->Root.pPrev;
      v14->Root.pPrev = (Scaleform::Render::DIQueuePage *)v14;
      v5->Queues[0].Root.pNext = (Scaleform::Render::DIQueuePage *)v5->Queues;
      v16->pNext = (Scaleform::Render::DIQueuePage *)v8;
      v15->pPrev = *(Scaleform::Render::DIQueuePage **)v8;
      *(_QWORD *)(*(_QWORD *)v8 + 8i64) = v15;
      *(_QWORD *)v8 = v16;
    }
  }
  Scaleform::Mutex::Unlock(v6);
}

// File Line: 252
// RVA: 0x9CB7B0
char *__fastcall Scaleform::Render::DICommandQueue::allocCommandFromPage(Scaleform::Render::DICommandQueue *this, unsigned int size, Scaleform::Lock *locked)
{
  Scaleform::Lock *v3; // rbp
  unsigned int v4; // esi
  Scaleform::Render::DIQueuePage *v5; // r9
  Scaleform::Render::DICommandQueue *v6; // rbx
  __int64 v7; // rcx
  char *result; // rax

  v3 = locked;
  v4 = size;
  v5 = this->Queues[0].Root.pPrev;
  v6 = this;
  if ( v5 == (Scaleform::Render::DIQueuePage *)this->Queues || size > 496 - v5->Offset )
  {
    if ( !this->FreePageCount && this->AllocPageCount >= 0x10 )
    {
      LeaveCriticalSection(&locked->cs);
      _InterlockedExchangeAdd(&v6->RefCount, 1u);
      _InterlockedExchangeAdd(&v6->ExecuteCmd.pObject->RefCount, 1u);
      v6->pRTCommandQueue->vfptr->PushThreadCommand(
        v6->pRTCommandQueue,
        (Scaleform::Render::ThreadCommand *)v6->ExecuteCmd.pObject);
      Scaleform::Render::DICommandQueue::ExecuteCommand::WaitDoneAndReset(v6->ExecuteCmd.pObject);
      EnterCriticalSection(&v3->cs);
    }
    v5 = Scaleform::Render::DICommandQueue::allocPage(v6);
  }
  if ( !v5 )
    return 0i64;
  v7 = v5->Offset;
  if ( v4 > 496 - (signed int)v7 )
    return 0i64;
  result = &v5->Buffer[v7];
  v5->Offset = v4 + v7;
  return result;
}

// File Line: 274
// RVA: 0x9CD030
Scaleform::Render::DIQueuePage *__fastcall Scaleform::Render::DICommandQueue::allocPage(Scaleform::Render::DICommandQueue *this)
{
  Scaleform::Render::DICommandQueue *v1; // rbx
  Scaleform::Render::DIQueuePage *v2; // r8
  __int64 v3; // rax
  Scaleform::Render::DIQueuePage *result; // rax
  int v5; // [rsp+48h] [rbp+10h]
  __int64 v6; // [rsp+50h] [rbp+18h]

  v1 = this;
  if ( (Scaleform::List<Scaleform::Render::DIQueuePage,Scaleform::Render::DIQueuePage> *)this->Queues[3].Root.pNext == &this->Queues[3] )
  {
    v5 = 2;
    v3 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::DICommandQueue *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
           Scaleform::Memory::pGlobalHeap,
           this,
           520i64,
           &v5,
           -2i64);
    v2 = (Scaleform::Render::DIQueuePage *)v3;
    v6 = v3;
    if ( v3 )
      *(_QWORD *)(v3 + 512) = 0i64;
    else
      v2 = 0i64;
  }
  else
  {
    v2 = this->Queues[3].Root.pNext;
    v2->pPrev->pNext = v2->pNext;
    v2->pNext->pPrev = v2->pPrev;
    v2->pPrev = (Scaleform::Render::DIQueuePage *)-1i64;
    v2->pNext = (Scaleform::Render::DIQueuePage *)-1i64;
    --this->FreePageCount;
  }
  result = v2;
  if ( v2 )
  {
    v2->pPrev = v1->Queues[0].Root.pPrev;
    v2->pNext = (Scaleform::Render::DIQueuePage *)v1->Queues;
    v1->Queues[0].Root.pPrev->pNext = v2;
    v1->Queues[0].Root.pPrev = v2;
  }
  return result;
}

// File Line: 326
// RVA: 0x9F8B70
void __fastcall Scaleform::Render::DICommandQueue::updateCPUModifiedImagesRT(Scaleform::Render::DICommandQueue *this)
{
  Scaleform::Render::DICommandQueue *v1; // rbp
  _RTL_CRITICAL_SECTION *v2; // rsi
  Scaleform::Render::DrawableImage *v3; // rdi
  Scaleform::Render::DrawableImage *v4; // rcx
  Scaleform::Render::DrawableImage *v5; // rbx
  Scaleform::Render::DrawableImage *v6; // rcx
  Scaleform::Render::DrawableImage *v7; // rcx
  Scaleform::Render::DrawableImage *v8; // rdi
  bool v9; // zf
  Scaleform::Render::DrawableImage *v10; // [rsp+60h] [rbp+8h]
  Scaleform::Lock *v11; // [rsp+70h] [rbp+18h]

  v1 = this;
  v2 = &this->QueueLock.cs;
  v11 = &this->QueueLock;
  EnterCriticalSection(&this->QueueLock.cs);
  v3 = 0i64;
  v4 = v1->pCPUModifiedImageList.pObject;
  if ( v4 )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *))v4->vfptr[1].__vecDelDtor)(v4);
  v5 = v1->pCPUModifiedImageList.pObject;
  v6 = v1->pCPUModifiedImageList.pObject;
  if ( v6 )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *))v6->vfptr[2].__vecDelDtor)(v6);
  v1->pCPUModifiedImageList.pObject = 0i64;
  if ( v5 )
  {
    do
    {
      if ( v5 )
        ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v5->vfptr[1].__vecDelDtor)(v5);
      if ( v3 )
        ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v3->vfptr[2].__vecDelDtor)(v3);
      v10 = v5;
      Scaleform::Render::DrawableImage::updateRenderTargetRT(v5);
      v7 = v5->pCPUModifiedNext.pObject;
      if ( v7 )
        ((void (__cdecl *)(Scaleform::Render::DrawableImage *))v7->vfptr[1].__vecDelDtor)(v7);
      if ( v5 )
        ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v5->vfptr[2].__vecDelDtor)(v5);
      v8 = v5->pCPUModifiedNext.pObject;
      if ( v8 )
        ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v8->vfptr[2].__vecDelDtor)(v5->pCPUModifiedNext.pObject);
      v5->pCPUModifiedNext.pObject = 0i64;
      v5->DrawableImageState &= 0xFFFFFFF7;
      v5 = v8;
      v9 = v8 == 0i64;
      v3 = v10;
    }
    while ( !v9 );
    v2 = &v11->cs;
  }
  if ( v5 )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v5->vfptr[2].__vecDelDtor)(v5);
  if ( v3 )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v3->vfptr[2].__vecDelDtor)(v3);
  LeaveCriticalSection(v2);
}

// File Line: 348
// RVA: 0x9F9D40
void __fastcall Scaleform::Render::DICommandQueue::updateGPUModifiedImagesRT(Scaleform::Render::DICommandQueue *this)
{
  Scaleform::Render::DICommandQueue *v1; // rbp
  _RTL_CRITICAL_SECTION *v2; // rsi
  Scaleform::Render::DrawableImage *v3; // rdi
  Scaleform::Render::DrawableImage *v4; // rcx
  Scaleform::Render::DrawableImage *v5; // rbx
  Scaleform::Render::DrawableImage *v6; // rcx
  Scaleform::Render::DrawableImage *v7; // rcx
  Scaleform::Render::DrawableImage *v8; // rdi
  bool v9; // zf
  Scaleform::Render::DrawableImage *v10; // [rsp+60h] [rbp+8h]
  Scaleform::Lock *v11; // [rsp+70h] [rbp+18h]

  v1 = this;
  v2 = &this->QueueLock.cs;
  v11 = &this->QueueLock;
  EnterCriticalSection(&this->QueueLock.cs);
  v3 = 0i64;
  v4 = v1->pGPUModifiedImageList.pObject;
  if ( v4 )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *))v4->vfptr[1].__vecDelDtor)(v4);
  v5 = v1->pGPUModifiedImageList.pObject;
  v6 = v1->pGPUModifiedImageList.pObject;
  if ( v6 )
    ((void (__cdecl *)(Scaleform::Render::DrawableImage *))v6->vfptr[2].__vecDelDtor)(v6);
  v1->pGPUModifiedImageList.pObject = 0i64;
  if ( v5 )
  {
    do
    {
      if ( v5 )
        ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v5->vfptr[1].__vecDelDtor)(v5);
      if ( v3 )
        ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v3->vfptr[2].__vecDelDtor)(v3);
      v10 = v5;
      Scaleform::Render::DrawableImage::updateStagingTargetRT(v5);
      v7 = v5->pGPUModifiedNext.pObject;
      if ( v7 )
        ((void (__cdecl *)(Scaleform::Render::DrawableImage *))v7->vfptr[1].__vecDelDtor)(v7);
      if ( v5 )
        ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v5->vfptr[2].__vecDelDtor)(v5);
      v8 = v5->pGPUModifiedNext.pObject;
      if ( v8 )
        ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v8->vfptr[2].__vecDelDtor)(v5->pGPUModifiedNext.pObject);
      v5->pGPUModifiedNext.pObject = 0i64;
      v5->DrawableImageState &= 0xFFFFFFEF;
      v5 = v8;
      v9 = v8 == 0i64;
      v3 = v10;
    }
    while ( !v9 );
    v2 = &v11->cs;
  }
  if ( v5 )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v5->vfptr[2].__vecDelDtor)(v5);
  if ( v3 )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v3->vfptr[2].__vecDelDtor)(v3);
  LeaveCriticalSection(v2);
}

// File Line: 371
// RVA: 0x99C900
void __fastcall Scaleform::Render::DICommandQueue::OnCapture(Scaleform::Render::DICommandQueue *this)
{
  Scaleform::Render::DICommandQueue *v1; // rsi
  Scaleform::Mutex *v2; // rbx
  _RTL_CRITICAL_SECTION *v3; // rdi
  Scaleform::List<Scaleform::Render::DIQueuePage,Scaleform::Render::DIQueuePage> *v4; // rax
  signed __int64 v5; // rsi
  Scaleform::Render::DIQueuePage *v6; // rdx
  Scaleform::Render::DIQueuePage *v7; // rcx

  v1 = this;
  v2 = &this->CommandSetMutex;
  Scaleform::Mutex::DoLock(&this->CommandSetMutex);
  while ( v1->pRTCommands )
    Scaleform::WaitCondition::Wait(&v1->CommandSetWC, v2, 0xFFFFFFFF);
  v3 = &v1->QueueLock.cs;
  EnterCriticalSection(&v1->QueueLock.cs);
  v4 = v1->Queues;
  v5 = (signed __int64)&v1->Queues[1];
  v6 = v4->Root.pNext;
  if ( v6 != (Scaleform::Render::DIQueuePage *)v4 )
  {
    v7 = v4->Root.pPrev;
    v4->Root.pPrev = (Scaleform::Render::DIQueuePage *)v4;
    v4->Root.pNext = (Scaleform::Render::DIQueuePage *)v4;
    v7->pNext = (Scaleform::Render::DIQueuePage *)v5;
    v6->pPrev = *(Scaleform::Render::DIQueuePage **)v5;
    *(_QWORD *)(*(_QWORD *)v5 + 8i64) = v6;
    *(_QWORD *)v5 = v7;
  }
  LeaveCriticalSection(v3);
  Scaleform::Mutex::Unlock(v2);
}

// File Line: 403
// RVA: 0x9741E0
void __fastcall Scaleform::Render::DICommandQueue::ExecuteNextCapture(Scaleform::Render::DICommandQueue *this, Scaleform::Render::ContextImpl::RenderNotify *pnotify)
{
  Scaleform::Render::DICommandQueue *v2; // rsi
  Scaleform::Render::ThreadCommandQueue *v3; // rcx
  Scaleform::List<Scaleform::Render::DIQueuePage,Scaleform::Render::DIQueuePage> *v4; // rax
  signed __int64 v5; // r14
  Scaleform::Render::DIQueuePage *v6; // rdx
  Scaleform::Render::DIQueuePage *v7; // rcx
  Scaleform::Render::DIQueuePage *v8; // rdx
  Scaleform::Render::DIQueuePage *v9; // rcx
  Scaleform::Render::DICommandContext context; // [rsp+28h] [rbp-48h]
  Scaleform::Render::DICommandSet v11; // [rsp+38h] [rbp-38h]
  __int64 v12; // [rsp+50h] [rbp-20h]
  Scaleform::Render::HAL *v13; // [rsp+58h] [rbp-18h]
  Scaleform::Render::Renderer2D *v14; // [rsp+60h] [rbp-10h]
  __int64 v15; // [rsp+68h] [rbp-8h]

  v2 = this;
  if ( !this->pRTCommandQueue && pnotify )
    this->pRTCommandQueue = pnotify->pRTCommandQueue;
  v3 = this->pRTCommandQueue;
  v12 = 0i64;
  v13 = 0i64;
  v14 = 0i64;
  v15 = 0i64;
  if ( v3 )
  {
    v3->vfptr->GetRenderInterfaces(v3, (Scaleform::Render::Interfaces *)&v12);
    context.pR2D = v14;
    context.pHAL = v13;
  }
  v11.pQueue = v2;
  v11.QueueList.Root.pPrev = (Scaleform::Render::DIQueuePage *)&v11.QueueList;
  v11.QueueList.Root.pNext = (Scaleform::Render::DIQueuePage *)&v11.QueueList;
  Scaleform::Mutex::DoLock(&v2->CommandSetMutex);
  EnterCriticalSection(&v2->QueueLock.cs);
  v4 = &v2->Queues[1];
  v5 = (signed __int64)&v2->Queues[2];
  v6 = v2->Queues[1].Root.pNext;
  if ( v6 != (Scaleform::Render::DIQueuePage *)&v2->Queues[1] )
  {
    v7 = v4->Root.pPrev;
    v4->Root.pPrev = (Scaleform::Render::DIQueuePage *)v4;
    v2->Queues[1].Root.pNext = (Scaleform::Render::DIQueuePage *)&v2->Queues[1];
    v7->pNext = (Scaleform::Render::DIQueuePage *)v5;
    v6->pPrev = *(Scaleform::Render::DIQueuePage **)v5;
    *(_QWORD *)(*(_QWORD *)v5 + 8i64) = v6;
    *(_QWORD *)v5 = v7;
  }
  Scaleform::Mutex::DoLock(&v2->CommandSetMutex);
  v8 = v2->Queues[2].Root.pNext;
  if ( v8 != (Scaleform::Render::DIQueuePage *)v5 )
  {
    v9 = *(Scaleform::Render::DIQueuePage **)v5;
    *(_QWORD *)v5 = v5;
    v2->Queues[2].Root.pNext = (Scaleform::Render::DIQueuePage *)&v2->Queues[2];
    v9->pNext = (Scaleform::Render::DIQueuePage *)&v11.QueueList;
    v8->pPrev = v11.QueueList.Root.pPrev;
    v11.QueueList.Root.pPrev->pNext = v8;
    v11.QueueList.Root.pPrev = v9;
  }
  Scaleform::Mutex::Unlock(&v2->CommandSetMutex);
  v2->pRTCommands = &v11;
  LeaveCriticalSection(&v2->QueueLock.cs);
  Scaleform::Mutex::Unlock(&v2->CommandSetMutex);
  Scaleform::Render::DICommandSet::ExecuteCommandsRT(&v11, &context);
  Scaleform::Mutex::DoLock(&v2->CommandSetMutex);
  v2->pRTCommands = 0i64;
  Scaleform::WaitCondition::NotifyAll(&v2->CommandSetWC);
  Scaleform::Mutex::Unlock(&v2->CommandSetMutex);
}

// File Line: 451
// RVA: 0x96E350
void __fastcall Scaleform::Render::DICommandQueue::DiscardCommands(Scaleform::Render::DICommandQueue *this)
{
  Scaleform::Render::DIQueuePage *i; // rbx
  signed __int64 v2; // rsi
  unsigned __int64 v3; // rdi
  Scaleform::Render::DICommandSet cmdSet; // [rsp+20h] [rbp-28h]

  cmdSet.QueueList.Root.pPrev = (Scaleform::Render::DIQueuePage *)&cmdSet.QueueList;
  cmdSet.pQueue = this;
  cmdSet.QueueList.Root.pNext = (Scaleform::Render::DIQueuePage *)&cmdSet.QueueList;
  Scaleform::Render::DICommandQueue::popCommandSet(this, &cmdSet, 0);
  for ( i = cmdSet.QueueList.Root.pNext;
        (Scaleform::List<Scaleform::Render::DIQueuePage,Scaleform::Render::DIQueuePage> *)cmdSet.QueueList.Root.pNext != &cmdSet.QueueList;
        i = cmdSet.QueueList.Root.pNext )
  {
    i->pPrev->pNext = i->pNext;
    i->pNext->pPrev = i->pPrev;
    i->pPrev = (Scaleform::Render::DIQueuePage *)-1i64;
    i->pNext = (Scaleform::Render::DIQueuePage *)-1i64;
    if ( i->Offset )
    {
      v2 = (signed __int64)i->Buffer;
      if ( i != (Scaleform::Render::DIQueuePage *)-16i64 )
      {
        do
        {
          (*(void (__fastcall **)(signed __int64))(*(_QWORD *)v2 + 64i64))(v2);
          v3 = v2 + (*(unsigned int (__fastcall **)(signed __int64))(*(_QWORD *)v2 + 32i64))(v2);
          if ( v3 >= (unsigned __int64)&i->Buffer[i->Offset] )
            v3 = 0i64;
          (**(void (__fastcall ***)(signed __int64, _QWORD))v2)(v2, 0i64);
          v2 = v3;
        }
        while ( v3 );
      }
    }
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, i);
  }
}

// File Line: 472
// RVA: 0x971E30
void __fastcall Scaleform::Render::DICommandQueue::ExecuteCommand::Execute(Scaleform::Render::DICommandQueue::ExecuteCommand *this)
{
  Scaleform::Render::DICommandQueue::ExecuteCommand *v1; // rdi
  Scaleform::Render::ThreadCommandQueue *v2; // rcx
  Scaleform::Mutex *v3; // rbx
  Scaleform::Render::DICommandQueue *v4; // rcx
  Scaleform::Render::DICommandContext context; // [rsp+28h] [rbp-50h]
  Scaleform::Render::DICommandSet cmdSet; // [rsp+38h] [rbp-40h]
  __int64 v7; // [rsp+50h] [rbp-28h]
  Scaleform::Render::HAL *v8; // [rsp+58h] [rbp-20h]
  Scaleform::Render::Renderer2D *v9; // [rsp+60h] [rbp-18h]
  __int64 v10; // [rsp+68h] [rbp-10h]

  v1 = this;
  v2 = this->pQueue->pRTCommandQueue;
  v7 = 0i64;
  v8 = 0i64;
  v9 = 0i64;
  v10 = 0i64;
  if ( v2 )
  {
    v2->vfptr->GetRenderInterfaces(v2, (Scaleform::Render::Interfaces *)&v7);
    context.pR2D = v9;
    context.pHAL = v8;
  }
  cmdSet.pQueue = v1->pQueue;
  cmdSet.QueueList.Root.pPrev = (Scaleform::Render::DIQueuePage *)&cmdSet.QueueList;
  cmdSet.QueueList.Root.pNext = (Scaleform::Render::DIQueuePage *)&cmdSet.QueueList;
  Scaleform::Render::DICommandQueue::popCommandSet(cmdSet.pQueue, &cmdSet, 0);
  v1->pQueue->pRTCommands = &cmdSet;
  Scaleform::Render::DICommandSet::ExecuteCommandsRT(&cmdSet, &context);
  v3 = &v1->pQueue->CommandSetMutex;
  Scaleform::Mutex::DoLock(v3);
  v1->pQueue->pRTCommands = 0i64;
  Scaleform::WaitCondition::NotifyAll(&v1->pQueue->CommandSetWC);
  Scaleform::Mutex::Unlock(v3);
  v4 = v1->pQueue;
  if ( !_InterlockedDecrement(&v4->RefCount) && v4 )
    v4->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, 1u);
  Scaleform::Event::SetEvent(&v1->ExecuteDone);
  if ( !_InterlockedDecrement(&v1->RefCount) )
    v1->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v1->vfptr, 1u);
}

// File Line: 545
// RVA: 0x971F60
void __fastcall Scaleform::Render::DICommandSet::ExecuteCommandsRT(Scaleform::Render::DICommandSet *this, Scaleform::Render::DICommandContext *context)
{
  Scaleform::Render::DICommandSet *v2; // r13
  Scaleform::Render::HAL *v3; // r12
  char v4; // di
  char v5; // bl
  char v6; // si
  Scaleform::List<Scaleform::Render::DIQueuePage,Scaleform::Render::DIQueuePage> *v7; // rax
  __int64 v8; // r8
  __int64 v9; // r14
  __int64 v10; // rax
  Scaleform::Render::DICommand *v11; // r15
  Scaleform::Render::DrawableImage *v12; // rbx
  char v13; // si
  Scaleform::Render::DrawableImage *v14; // r13
  unsigned int v15; // eax
  char v16; // r14
  Scaleform::Render::DICommand *v17; // rdi
  signed int *v18; // rax
  float v19; // xmm1_4
  float v20; // xmm0_4
  Scaleform::RefCountImplCoreVtbl *v21; // rdi
  __int64 v22; // rax
  signed int v23; // er15
  signed int v24; // esi
  int v25; // er14
  int v26; // edi
  int *v27; // rax
  int v28; // er15
  int v29; // ecx
  int v30; // eax
  Scaleform::Render::RenderSync *v31; // rax
  Scaleform::Render::Fence *v32; // rax
  __int64 v33; // rdx
  Scaleform::Render::Fence *v34; // rsi
  bool v35; // zf
  Scaleform::Render::FenceImpl *v36; // rcx
  Scaleform::Render::RenderSync *v37; // rdi
  Scaleform::Render::FenceImpl *v38; // rcx
  __int64 v39; // rax
  __int64 v40; // rax
  signed int *v41; // rax
  float v42; // xmm1_4
  float v43; // xmm0_4
  Scaleform::RefCountImplCoreVtbl *v44; // rdi
  __int64 v45; // rax
  signed int v46; // er15
  signed int v47; // esi
  Scaleform::Render::DICommand *v48; // rdi
  Scaleform::Render::RenderSync *v49; // rax
  Scaleform::Render::Fence *v50; // rax
  Scaleform::Render::Fence *v51; // rdi
  Scaleform::Render::Fence *v52; // rcx
  __int64 v53; // rax
  Scaleform::Render::DICommandQueue *v54; // rdx
  char v55; // [rsp+30h] [rbp-A9h]
  char v56; // [rsp+31h] [rbp-A8h]
  unsigned __int8 v57; // [rsp+32h] [rbp-A7h]
  Scaleform::Render::Color backgroundColor; // [rsp+34h] [rbp-A5h]
  Scaleform::Render::DICommand *v59; // [rsp+38h] [rbp-A1h]
  __int64 v60; // [rsp+40h] [rbp-99h]
  float v61; // [rsp+48h] [rbp-91h]
  float v62; // [rsp+4Ch] [rbp-8Dh]
  __int64 v63; // [rsp+50h] [rbp-89h]
  float v64; // [rsp+58h] [rbp-81h]
  float v65; // [rsp+5Ch] [rbp-7Dh]
  Scaleform::Render::Viewport vpin; // [rsp+60h] [rbp-79h]
  Scaleform::Render::DrawableImage *v67; // [rsp+90h] [rbp-49h]
  __int64 v68; // [rsp+98h] [rbp-41h]
  Scaleform::Render::HALEndDisplayItem *v69; // [rsp+A0h] [rbp-39h]
  __int64 v70; // [rsp+A8h] [rbp-31h]
  Scaleform::Render::HALEndDisplayItem *v71; // [rsp+B0h] [rbp-29h]
  __int64 v72; // [rsp+B8h] [rbp-21h]
  Scaleform::Render::DrawableImage *v73; // [rsp+C0h] [rbp-19h]
  char v74; // [rsp+C8h] [rbp-11h]
  __int64 v75; // [rsp+D0h] [rbp-9h]
  char v76; // [rsp+D8h] [rbp-1h]
  char v77; // [rsp+E0h] [rbp+7h]
  char v78; // [rsp+E8h] [rbp+Fh]
  Scaleform::Render::DICommandSet *v79; // [rsp+140h] [rbp+67h]
  Scaleform::Render::DICommandContext *contexta; // [rsp+148h] [rbp+6Fh]
  char v81; // [rsp+150h] [rbp+77h]
  Scaleform::Render::Fence *v82; // [rsp+158h] [rbp+7Fh]

  contexta = context;
  v79 = this;
  v75 = -2i64;
  v2 = this;
  v3 = context->pHAL;
  LOBYTE(context) = 0;
  v57 = 0;
  v4 = 0;
  v81 = 0;
  v5 = 1;
  v56 = 1;
  v6 = 0;
  v55 = 0;
  v7 = &this->QueueList;
  if ( (Scaleform::List<Scaleform::Render::DIQueuePage,Scaleform::Render::DIQueuePage> *)this->QueueList.Root.pNext != &this->QueueList )
  {
    v8 = 0i64;
    do
    {
      v9 = (__int64)v2->QueueList.Root.pNext;
      v68 = v9;
      *(_QWORD *)(*(_QWORD *)v9 + 8i64) = *(_QWORD *)(v9 + 8);
      **(_QWORD **)(v9 + 8) = *(_QWORD *)v9;
      *(_QWORD *)v9 = -1i64;
      *(_QWORD *)(v9 + 8) = -1i64;
      if ( !(_BYTE)context )
      {
        v10 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *, signed __int64, _QWORD))v3->vfptr[60].__vecDelDtor)(
                v3,
                15i64,
                0i64);
        (*(void (__fastcall **)(__int64, const char *))(*(_QWORD *)v10 + 16i64))(
          v10,
          "Scaleform::Render::DrawableImage");
        v57 = 1;
        v8 = 0i64;
      }
      v11 = (Scaleform::Render::DICommand *)(v9 + 16);
      if ( !*(_DWORD *)(v9 + 512) )
        v11 = 0i64;
      v59 = v11;
      v12 = 0i64;
      v67 = 0i64;
      v13 = 0;
      LOBYTE(v82) = 0;
      if ( v11 )
      {
        while ( 1 )
        {
          v14 = v11->pImage.pObject;
          if ( v14 )
            ((void (__fastcall *)(Scaleform::Render::DrawableImage *, Scaleform::Render::DICommandContext *, __int64))v14->vfptr[1].__vecDelDtor)(
              v11->pImage.pObject,
              context,
              v8);
          v73 = v14;
          v15 = ((__int64 (__fastcall *)(Scaleform::Render::DICommand *, Scaleform::Render::DICommandContext *, __int64))v11->vfptr->GetRenderCaps)(
                  v11,
                  context,
                  v8);
          if ( v12 == v14 && v12 && v13 )
          {
            v16 = (v15 >> 1) & 1;
            if ( !v16 )
              goto LABEL_31;
          }
          else
          {
            if ( !(v15 & 4) && v15 & 1 || v15 & 8 )
            {
              v16 = 0;
LABEL_31:
              if ( (!v12 || !v13) && v16 )
              {
                if ( !v4 )
                {
                  if ( v3->HALState & 4 )
                  {
                    v55 = 1;
                    ((void (__fastcall *)(Scaleform::Render::HAL *))v3->vfptr[10].__vecDelDtor)(v3);
                  }
                  if ( !(v3->HALState & 2) )
                  {
                    ((void (__fastcall *)(Scaleform::Render::HAL *))v3->vfptr[5].__vecDelDtor)(v3);
                    v56 = 0;
                  }
                  v81 = 1;
                }
                if ( v14 )
                  ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v14->vfptr[1].__vecDelDtor)(v14);
                if ( v12 )
                  ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v12->vfptr[2].__vecDelDtor)(v12);
                v12 = v14;
                v67 = v14;
                v18 = (signed int *)v14->vfptr[5].__vecDelDtor(
                                      (Scaleform::RefCountImplCore *)&v14->vfptr,
                                      (unsigned int)&v77);
                v19 = (float)v18[1];
                v20 = (float)*v18;
                v60 = 0i64;
                v61 = v20;
                v62 = v19;
                LODWORD(v82) = 0;
                v21 = v3->vfptr;
                v22 = ((__int64 (__fastcall *)(Scaleform::Render::DrawableImage *))v14->vfptr[26].__vecDelDtor)(v14);
                ((void (__fastcall *)(Scaleform::Render::HAL *, __int64 *, __int64, signed __int64, Scaleform::Render::Fence **))v21[24].__vecDelDtor)(
                  v3,
                  &v60,
                  v22,
                  3i64,
                  &v82);
                LOBYTE(v82) = 1;
                ((void (__fastcall *)(Scaleform::Render::HAL *))v3->vfptr[9].__vecDelDtor)(v3);
                v23 = (signed int)v62;
                v24 = (signed int)v61;
                v25 = (signed int)*((float *)&v60 + 1);
                v26 = (signed int)*(float *)&v60;
                v27 = (int *)v14->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v14->vfptr, (unsigned int)&v74);
                vpin.Width = v24 - v26;
                v28 = v23 - v25;
                vpin.Flags = 1;
                *(_QWORD *)&vpin.ScissorWidth = 0i64;
                *(_QWORD *)&vpin.ScissorLeft = 0i64;
                goto LABEL_45;
              }
              if ( v12 != v14 )
              {
                if ( v13 )
                {
                  if ( v14 )
                    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v14->vfptr[1].__vecDelDtor)(v14);
                  if ( v12 )
                    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v12->vfptr[2].__vecDelDtor)(v12);
                  v12 = v14;
                  v67 = v14;
                  if ( v3->HALState & 0x400 )
                  {
                    ((void (__fastcall *)(Scaleform::Render::HAL *))v3->vfptr[8].__vecDelDtor)(v3);
                    ((void (__fastcall *)(Scaleform::Render::HAL *))v3->vfptr[12].__vecDelDtor)(v3);
                  }
                  else
                  {
                    v69 = &Scaleform::Render::HALEndDisplayItem::Instance;
                    v70 = 0i64;
                    v3->vfptr[33].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, (unsigned int)&v69);
                  }
                  ((void (__fastcall *)(Scaleform::Render::HAL *))v3->vfptr[10].__vecDelDtor)(v3);
                  Scaleform::Render::DICommandQueue::updateCPUModifiedImagesRT(v79->pQueue);
                  v3->vfptr[25].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, 2u);
                  if ( ((__int64 (*)(void))contexta->pHAL->vfptr[65].__vecDelDtor)() )
                  {
                    v31 = (Scaleform::Render::RenderSync *)((__int64 (*)(void))contexta->pHAL->vfptr[65].__vecDelDtor)();
                    v32 = Scaleform::Render::RenderSync::InsertFence(v31);
                    v33 = (__int64)v32;
                    v82 = v32;
                    if ( v32 )
                      ++v32->RefCount;
                    v34 = v14->pFence.pObject;
                    if ( v34 )
                    {
                      v35 = v34->RefCount-- == 1;
                      if ( v35 )
                      {
                        v36 = v34->Data;
                        if ( v34->HasData )
                        {
                          v37 = v36->RSContext;
                          ((void (__fastcall *)(Scaleform::Render::FenceImpl *, unsigned __int64))v36->RSContext->FenceFrameAlloc.pHeapOrPtr)(
                            v36,
                            v36->APIHandle);
                          v38 = v34->Data;
                          v38->RSContext = (Scaleform::Render::RenderSync *)v37->FenceImplAlloc.FirstEmptySlot;
                          v37->FenceImplAlloc.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> >::NodeType *)v38;
                          v34->Data = (Scaleform::Render::FenceImpl *)v37->FenceAlloc.FirstEmptySlot;
                          v37->FenceAlloc.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> >::NodeType *)v34;
                          v33 = (__int64)v82;
                        }
                        else
                        {
                          v34->Data = (Scaleform::Render::FenceImpl *)v36[4].Parent;
                          v36[4].Parent = (Scaleform::Render::FenceFrame *)v34;
                        }
                      }
                    }
                    v14->pFence.pObject = (Scaleform::Render::Fence *)v33;
                  }
                  LOBYTE(v82) = 0;
                }
                v39 = (__int64)v3->vfptr[60].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, 15u);
                (*(void (__fastcall **)(__int64))(*(_QWORD *)v39 + 24i64))(v39);
                v40 = (__int64)v3->vfptr[60].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, 15u);
                (*(void (__fastcall **)(__int64, const char *))(*(_QWORD *)v40 + 16i64))(
                  v40,
                  "Scaleform::Render::DrawableImage");
                if ( v16 )
                {
                  if ( !v81 )
                  {
                    if ( v3->HALState & 4 )
                    {
                      v55 = 1;
                      ((void (__fastcall *)(Scaleform::Render::HAL *))v3->vfptr[10].__vecDelDtor)(v3);
                    }
                    if ( !(v3->HALState & 2) )
                    {
                      ((void (__fastcall *)(Scaleform::Render::HAL *))v3->vfptr[5].__vecDelDtor)(v3);
                      v56 = 0;
                    }
                    v81 = 1;
                  }
                  v41 = (signed int *)v12->vfptr[5].__vecDelDtor(
                                        (Scaleform::RefCountImplCore *)&v12->vfptr,
                                        (unsigned int)&v76);
                  v42 = (float)v41[1];
                  v43 = (float)*v41;
                  v63 = 0i64;
                  v64 = v43;
                  v65 = v42;
                  LODWORD(v82) = 0;
                  v44 = v3->vfptr;
                  v45 = ((__int64 (__fastcall *)(Scaleform::Render::DrawableImage *))v12->vfptr[26].__vecDelDtor)(v12);
                  ((void (__fastcall *)(Scaleform::Render::HAL *, __int64 *, __int64, signed __int64, Scaleform::Render::Fence **))v44[24].__vecDelDtor)(
                    v3,
                    &v63,
                    v45,
                    3i64,
                    &v82);
                  LOBYTE(v82) = 1;
                  ((void (__fastcall *)(Scaleform::Render::HAL *))v3->vfptr[9].__vecDelDtor)(v3);
                  v46 = (signed int)v65;
                  v47 = (signed int)v64;
                  v25 = (signed int)*((float *)&v63 + 1);
                  v26 = (signed int)*(float *)&v63;
                  v27 = (int *)v12->vfptr[5].__vecDelDtor(
                                 (Scaleform::RefCountImplCore *)&v12->vfptr,
                                 (unsigned int)&v78);
                  vpin.Width = v47 - v26;
                  v28 = v46 - v25;
                  *(_QWORD *)&vpin.ScissorHeight = 0i64;
                  *(_QWORD *)&vpin.ScissorTop = 0i64;
                  vpin.ScissorLeft = 0;
LABEL_45:
                  v29 = v27[1];
                  v30 = *v27;
                  vpin.Height = v28;
                  vpin.Top = v25;
                  vpin.Left = v26;
                  vpin.BufferHeight = v29;
                  vpin.BufferWidth = v30;
                  backgroundColor = 0;
                  Scaleform::Render::HAL::BeginDisplay(v3, (__int64)&backgroundColor, &vpin);
                  v11 = v59;
                }
              }
              Scaleform::Render::DICommand::ExecuteRT(v11, contexta);
              v48 = (Scaleform::Render::DICommand *)((char *)v11 + v11->vfptr->GetSize(v11));
              v9 = v68;
              if ( (unsigned __int64)v48 >= (unsigned __int64)*(unsigned int *)(v68 + 512) + v68 + 16 )
                v48 = 0i64;
              v11->vfptr->__vecDelDtor(v11, 0);
              v11 = v48;
              v59 = v48;
              if ( v14 )
                ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v14->vfptr[2].__vecDelDtor)(v14);
              v13 = (char)v82;
              goto LABEL_78;
            }
            v16 = 1;
          }
          if ( v14->pRT.pObject )
            goto LABEL_31;
          if ( !v4 )
          {
            if ( v3->HALState & 4 )
            {
              v55 = 1;
              ((void (__fastcall *)(Scaleform::Render::HAL *))v3->vfptr[10].__vecDelDtor)(v3);
            }
            if ( !(v3->HALState & 2) )
            {
              ((void (__fastcall *)(Scaleform::Render::HAL *))v3->vfptr[5].__vecDelDtor)(v3);
              v56 = 0;
            }
            v4 = 1;
            v81 = 1;
          }
          if ( Scaleform::Render::DrawableImage::ensureRenderableRT(v14) )
            goto LABEL_31;
          v17 = (Scaleform::Render::DICommand *)((char *)v11 + v11->vfptr->GetSize(v11));
          v9 = v68;
          if ( (unsigned __int64)v17 >= (unsigned __int64)*(unsigned int *)(v68 + 512) + v68 + 16 )
            v17 = 0i64;
          v11->vfptr->__vecDelDtor(v11, 0);
          v11 = v17;
          v59 = v17;
          ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v14->vfptr[2].__vecDelDtor)(v14);
LABEL_78:
          v4 = v81;
          if ( !v11 )
          {
            if ( v12 && v13 )
            {
              if ( v3->HALState & 0x400 )
              {
                ((void (__fastcall *)(Scaleform::Render::HAL *))v3->vfptr[8].__vecDelDtor)(v3);
                ((void (__fastcall *)(Scaleform::Render::HAL *))v3->vfptr[12].__vecDelDtor)(v3);
              }
              else
              {
                v71 = &Scaleform::Render::HALEndDisplayItem::Instance;
                v72 = 0i64;
                v3->vfptr[33].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, (unsigned int)&v71);
              }
              ((void (__fastcall *)(Scaleform::Render::HAL *))v3->vfptr[10].__vecDelDtor)(v3);
              v2 = v79;
              Scaleform::Render::DICommandQueue::updateCPUModifiedImagesRT(v79->pQueue);
              v3->vfptr[25].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, 2u);
              if ( ((__int64 (*)(void))contexta->pHAL->vfptr[65].__vecDelDtor)() )
              {
                v49 = (Scaleform::Render::RenderSync *)((__int64 (*)(void))contexta->pHAL->vfptr[65].__vecDelDtor)();
                v50 = Scaleform::Render::RenderSync::InsertFence(v49);
                v51 = v50;
                if ( v50 )
                  ++v50->RefCount;
                v52 = v12->pFence.pObject;
                if ( v52 )
                  Scaleform::Render::Fence::Release(v52);
                v12->pFence.pObject = v51;
              }
            }
            else
            {
              v2 = v79;
            }
            v4 = v81;
            break;
          }
        }
      }
      if ( v57 )
      {
        v53 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *, signed __int64, __int64))v3->vfptr[60].__vecDelDtor)(
                v3,
                15i64,
                v8);
        (*(void (__fastcall **)(__int64))(*(_QWORD *)v53 + 24i64))(v53);
      }
      v54 = v2->pQueue;
      if ( v2->pQueue->FreePageCount >= 3 )
      {
        ((void (__fastcall *)(Scaleform::MemoryHeap *, __int64, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v9,
          v8);
      }
      else
      {
        *(_DWORD *)(v9 + 512) = 0;
        *(_QWORD *)v9 = v54->Queues[3].Root.pPrev;
        *(_QWORD *)(v9 + 8) = (char *)v54 + 208;
        v54->Queues[3].Root.pPrev->pNext = (Scaleform::Render::DIQueuePage *)v9;
        v54->Queues[3].Root.pPrev = (Scaleform::Render::DIQueuePage *)v9;
        ++v54->FreePageCount;
      }
      if ( v12 )
        ((void (__fastcall *)(Scaleform::Render::DrawableImage *, Scaleform::Render::DICommandQueue *, __int64))v12->vfptr[2].__vecDelDtor)(
          v12,
          v54,
          v8);
      v7 = &v2->QueueList;
      context = (Scaleform::Render::DICommandContext *)v57;
      v8 = 0i64;
    }
    while ( (Scaleform::List<Scaleform::Render::DIQueuePage,Scaleform::Render::DIQueuePage> *)v2->QueueList.Root.pNext != &v2->QueueList );
    v5 = v56;
    v6 = v55;
  }
  v7->Root.pPrev = (Scaleform::Render::DIQueuePage *)v7;
  v7->Root.pNext = (Scaleform::Render::DIQueuePage *)v7;
  Scaleform::Render::DICommandQueue::updateCPUModifiedImagesRT(v2->pQueue);
  Scaleform::Render::DICommandQueue::updateGPUModifiedImagesRT(v2->pQueue);
  if ( v4 )
  {
    if ( !v5 )
      ((void (__fastcall *)(Scaleform::Render::HAL *))v3->vfptr[6].__vecDelDtor)(v3);
    if ( v6 )
      ((void (__fastcall *)(Scaleform::Render::HAL *))v3->vfptr[9].__vecDelDtor)(v3);
  }
}

