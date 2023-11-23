// File Line: 37
// RVA: 0x98AF90
__int64 __fastcall Scaleform::Render::DICommand::GetRenderCaps(Scaleform::Render::DICommand *this)
{
  unsigned int v2; // ebx
  Scaleform::Render::DrawableImage *pObject; // rax
  Scaleform::Render::DrawableImageContext *v4; // rax
  Scaleform::Render::ThreadCommandQueue *pRTCommandQueue; // rcx
  __int64 v7; // [rsp+20h] [rbp-28h] BYREF
  __int64 v8; // [rsp+28h] [rbp-20h]
  __int64 v9; // [rsp+30h] [rbp-18h]
  __int64 v10; // [rsp+38h] [rbp-10h]

  v2 = this->vfptr->GetCPUCaps(this);
  pObject = this->pImage.pObject;
  if ( pObject
    && (v4 = pObject->pContext.pObject) != 0i64
    && (pRTCommandQueue = v4->pRTCommandQueue) != 0i64
    && (v7 = 0i64,
        v8 = 0i64,
        v9 = 0i64,
        v10 = 0i64,
        pRTCommandQueue->vfptr->GetRenderInterfaces(pRTCommandQueue, (Scaleform::Render::Interfaces *)&v7),
        v8) )
  {
    return v2 | (*(unsigned int (__fastcall **)(__int64, Scaleform::Render::DICommand *))(*(_QWORD *)v8 + 408i64))(
                  v8,
                  this);
  }
  else
  {
    return v2;
  }
}

// File Line: 68
// RVA: 0x977CB0
char __fastcall Scaleform::Render::DICommand::ExecuteSWOnAddCommand(
        Scaleform::Render::DICommand *this,
        Scaleform::Render::DrawableImage *i)
{
  char v4; // bp
  unsigned int imageCount; // r15d
  unsigned int v7; // edi
  Scaleform::Render::DISourceImages *p_images; // rbx
  Scaleform::Render::ThreadCommandQueue *pRTCommandQueue; // rcx
  char v10; // bl
  Scaleform::Render::DISourceImages images; // [rsp+38h] [rbp-70h] BYREF
  Scaleform::Render::DICommandContext context; // [rsp+48h] [rbp-60h] BYREF
  __int64 v13; // [rsp+58h] [rbp-50h] BYREF
  Scaleform::Render::HAL *v14; // [rsp+60h] [rbp-48h]
  Scaleform::Render::Renderer2D *v15; // [rsp+68h] [rbp-40h]
  __int64 v16; // [rsp+70h] [rbp-38h]
  Scaleform::Lock *lpCriticalSection; // [rsp+B0h] [rbp+8h]

  v4 = this->vfptr->GetRenderCaps(this);
  if ( (v4 & 1) == 0 )
    return 0;
  images.pImages[0] = 0i64;
  images.pImages[1] = 0i64;
  imageCount = this->vfptr->GetSourceImages(this, &images);
  lpCriticalSection = &i->pQueue.pObject->QueueLock;
  EnterCriticalSection(&lpCriticalSection->cs);
  if ( (i->DrawableImageState & 3) != 0 && i->RefCount <= 2 )
  {
    v7 = 0;
    p_images = &images;
    while ( !p_images->pImages[0]
         || ((unsigned int (__fastcall *)(Scaleform::Render::Image *))p_images->pImages[0]->vfptr[3].__vecDelDtor)(p_images->pImages[0]) != 6
         || (HIDWORD(p_images->pImages[0][1].pUpdateSync) & 3) != 0 && p_images->pImages[0]->RefCount <= 2 )
    {
      ++v7;
      p_images = (Scaleform::Render::DISourceImages *)((char *)p_images + 8);
      if ( v7 >= 2 )
      {
        pRTCommandQueue = i->pContext.pObject->pRTCommandQueue;
        v13 = 0i64;
        v14 = 0i64;
        v15 = 0i64;
        v16 = 0i64;
        if ( pRTCommandQueue )
        {
          pRTCommandQueue->vfptr->GetRenderInterfaces(pRTCommandQueue, (Scaleform::Render::Interfaces *)&v13);
          context.pR2D = v15;
          context.pHAL = v14;
        }
        Scaleform::Render::DICommand::executeSWHelper(this, &context, i, &images, imageCount);
        if ( (v4 & 0x20) == 0 )
          Scaleform::Render::DrawableImage::addToCPUModifiedList(i);
        v10 = 1;
        goto LABEL_17;
      }
    }
  }
  v10 = 0;
LABEL_17:
  LeaveCriticalSection(&lpCriticalSection->cs);
  return v10;
}

// File Line: 125
// RVA: 0x9743C0
void __fastcall Scaleform::Render::DICommand::ExecuteRT(
        Scaleform::Render::DICommand *this,
        Scaleform::Render::DICommandContext *context)
{
  char v4; // al
  Scaleform::Render::DICommandQueue *pObject; // rcx
  unsigned int imageCount; // ebp
  Scaleform::Render::DrawableImage *v7; // rbx
  char v8; // al
  Scaleform::Render::DISourceImages images; // [rsp+30h] [rbp-18h] BYREF

  v4 = this->vfptr->GetRenderCaps(this);
  pObject = this->pImage.pObject->pQueue.pObject;
  if ( (v4 & 5) == 1 )
  {
    Scaleform::Render::DICommandQueue::updateGPUModifiedImagesRT(pObject);
    images.pImages[0] = 0i64;
    images.pImages[1] = 0i64;
    imageCount = this->vfptr->GetSourceImages(this, &images);
    if ( (this->pImage.pObject->DrawableImageState & 3) != 0
      || (v7 = this->pImage.pObject,
          v8 = this->vfptr->GetRenderCaps(this),
          Scaleform::Render::DrawableImage::mapTextureRT(v7, (v8 & 0x20) != 0)) )
    {
      Scaleform::Render::DICommand::executeSWHelper(this, context, this->pImage.pObject, &images, imageCount);
    }
  }
  else
  {
    Scaleform::Render::DICommandQueue::updateCPUModifiedImagesRT(pObject);
    Scaleform::Render::DICommand::executeHWHelper(this, context, this->pImage.pObject);
  }
}

// File Line: 160
// RVA: 0x9E2950
char __fastcall Scaleform::Render::DICommand::executeSWHelper(
        Scaleform::Render::DICommand *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::DrawableImage *di,
        Scaleform::Render::DISourceImages *images,
        unsigned int imageCount)
{
  Scaleform::Render::ImageData *MappedData; // r14
  Scaleform::Render::DrawableImage *v10; // rdx
  Scaleform::Render::ImageData *p_ptr; // [rsp+30h] [rbp-B8h] BYREF
  Scaleform::Render::ImageData *p_data; // [rsp+38h] [rbp-B0h]
  __int64 v14; // [rsp+40h] [rbp-A8h]
  Scaleform::Render::ImageData ptr; // [rsp+50h] [rbp-98h] BYREF
  Scaleform::Render::ImageData data; // [rsp+90h] [rbp-58h] BYREF

  v14 = -2i64;
  MappedData = Scaleform::Render::DrawableImage::getMappedData(di);
  if ( imageCount )
  {
    `eh vector constructor iterator(
      &ptr,
      0x40ui64,
      2,
      (void (__fastcall *)(void *))Scaleform::Render::ImageData::ImageData);
    p_ptr = 0i64;
    p_data = 0i64;
    if ( images->pImages[0]
      && !Scaleform::Render::DrawableImage::MapImageSource(&ptr, (Scaleform::Render::DrawableImage *)images->pImages[0])
      || (p_ptr = &ptr, (v10 = (Scaleform::Render::DrawableImage *)images->pImages[1]) != 0i64)
      && !Scaleform::Render::DrawableImage::MapImageSource(&data, v10) )
    {
      `eh vector destructor iterator(
        &ptr,
        0x40ui64,
        2,
        (void (__fastcall *)(void *))Scaleform::Render::ImageData::~ImageData);
      return 0;
    }
    p_data = &data;
    ((void (__fastcall *)(Scaleform::Render::DICommand *, Scaleform::Render::DICommandContext *, Scaleform::Render::ImageData *, Scaleform::Render::ImageData **, void (__fastcall *)(Scaleform::Render::ImageData *)))this->vfptr->ExecuteSW)(
      this,
      context,
      MappedData,
      &p_ptr,
      Scaleform::Render::ImageData::~ImageData);
    `eh vector destructor iterator(
      &ptr,
      0x40ui64,
      2,
      (void (__fastcall *)(void *))Scaleform::Render::ImageData::~ImageData);
  }
  else
  {
    this->vfptr->ExecuteSW(this, context, MappedData, 0i64);
  }
  if ( (((__int64 (__fastcall *)(Scaleform::Render::DICommand *))this->vfptr->GetRenderCaps)(this) & 0x20) == 0 )
    Scaleform::Render::DrawableImage::addToCPUModifiedList(di);
  return 1;
}

// File Line: 193
// RVA: 0x9E28B0
char __fastcall Scaleform::Render::DICommand::executeHWHelper(
        Scaleform::Render::DICommand *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::DrawableImage *i)
{
  Scaleform::Lock *lpCriticalSection; // [rsp+40h] [rbp+8h]

  lpCriticalSection = &i->pQueue.pObject->QueueLock;
  EnterCriticalSection(&lpCriticalSection->cs);
  if ( (i->DrawableImageState & 3) != 0 && i->pTexture.Value )
  {
    ((void (__fastcall *)(Scaleform::Render::Texture *volatile))i->pTexture.Value->Scaleform::Render::Image::vfptr[14].__vecDelDtor)(i->pTexture.Value);
    i->DrawableImageState &= 0xFFFFFFFC;
  }
  LeaveCriticalSection(&lpCriticalSection->cs);
  this->vfptr->ExecuteHW(this, context);
  if ( (((__int64 (__fastcall *)(Scaleform::Render::DICommand *))this->vfptr->GetRenderCaps)(this) & 0xA) == 2 )
    Scaleform::Render::DrawableImage::addToGPUModifiedListRT(i);
  return 1;
}

// File Line: 216
// RVA: 0x939BD0
void __fastcall Scaleform::Render::DICommandQueue::DICommandQueue(
        Scaleform::Render::DICommandQueue *this,
        Scaleform::Render::DrawableImageContext *dicontext)
{
  Scaleform::Render::DICommandQueue::ExecuteCommand *v4; // rax
  Scaleform::Render::DICommandQueue::ExecuteCommand *v5; // rax

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::DICommandQueue,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::DICommandQueue::`vftable;
  Scaleform::Mutex::Mutex(&this->CommandSetMutex, 1, 0);
  Scaleform::WaitCondition::WaitCondition(&this->CommandSetWC);
  this->pRTCommands = 0i64;
  this->pCPUModifiedImageList.pObject = 0i64;
  this->pGPUModifiedImageList.pObject = 0i64;
  this->pRTCommandQueue = dicontext->pRTCommandQueue;
  Scaleform::Lock::Lock(&this->QueueLock, 0);
  v4 = (Scaleform::Render::DICommandQueue::ExecuteCommand *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                                              Scaleform::Memory::pGlobalHeap,
                                                              112i64,
                                                              0i64);
  if ( v4 )
    Scaleform::Render::DICommandQueue::ExecuteCommand::ExecuteCommand(v4, this);
  else
    v5 = 0i64;
  this->ExecuteCmd.pObject = v5;
  this->Queues[0].Root.pPrev = (Scaleform::Render::DIQueuePage *)this->Queues;
  this->Queues[0].Root.pNext = (Scaleform::Render::DIQueuePage *)this->Queues;
  this->Queues[1].Root.pPrev = (Scaleform::Render::DIQueuePage *)&this->Queues[1];
  this->Queues[1].Root.pNext = (Scaleform::Render::DIQueuePage *)&this->Queues[1];
  this->Queues[2].Root.pPrev = (Scaleform::Render::DIQueuePage *)&this->Queues[2];
  this->Queues[2].Root.pNext = (Scaleform::Render::DIQueuePage *)&this->Queues[2];
  this->Queues[3].Root.pPrev = (Scaleform::Render::DIQueuePage *)&this->Queues[3];
  this->Queues[3].Root.pNext = (Scaleform::Render::DIQueuePage *)&this->Queues[3];
  *(_QWORD *)&this->CaptureFrameId = 0i64;
  this->AllocPageCount = 0;
}

// File Line: 220
// RVA: 0x949590
void __fastcall Scaleform::Render::DICommandQueue::~DICommandQueue(Scaleform::Render::DICommandQueue *this)
{
  Scaleform::Lock *p_QueueLock; // rbx
  Scaleform::Render::DIQueuePage *pNext; // rdx
  Scaleform::Render::DICommandQueue::ExecuteCommand *pObject; // rcx
  Scaleform::Render::DrawableImage *v5; // rcx
  Scaleform::Render::DrawableImage *v6; // rcx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::DICommandQueue::`vftable;
  p_QueueLock = &this->QueueLock;
  EnterCriticalSection(&this->QueueLock.cs);
  while ( (Scaleform::List<Scaleform::Render::DIQueuePage,Scaleform::Render::DIQueuePage> *)this->Queues[3].Root.pNext != &this->Queues[3] )
  {
    pNext = this->Queues[3].Root.pNext;
    pNext->pPrev->pNext = pNext->pNext;
    pNext->pNext->Scaleform::ListNode<Scaleform::Render::DIQueuePage>::$44454289C2DA0525B3C059BFF249C3BE::pPrev = pNext->pPrev;
    pNext->pPrev = (Scaleform::Render::DIQueuePage *)-1i64;
    pNext->pNext = (Scaleform::Render::DIQueuePage *)-1i64;
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
  LeaveCriticalSection(&p_QueueLock->cs);
  pObject = this->ExecuteCmd.pObject;
  if ( pObject && _InterlockedExchangeAdd(&pObject->RefCount, 0xFFFFFFFF) == 1 )
    pObject->vfptr->__vecDelDtor(pObject, 1u);
  DeleteCriticalSection(&p_QueueLock->cs);
  v5 = this->pGPUModifiedImageList.pObject;
  if ( v5 )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v5->vfptr[2].__vecDelDtor)(v5);
  v6 = this->pCPUModifiedImageList.pObject;
  if ( v6 )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v6->vfptr[2].__vecDelDtor)(v6);
  Scaleform::WaitCondition::~WaitCondition(&this->CommandSetWC);
  Scaleform::Mutex::~Mutex(&this->CommandSetMutex);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 239
// RVA: 0x9EBEB0
void __fastcall Scaleform::Render::DICommandQueue::popCommandSet(
        Scaleform::Render::DICommandQueue *this,
        Scaleform::Render::DICommandSet *cmdSet,
        Scaleform::Render::DICommandSetType type)
{
  Scaleform::Mutex *p_CommandSetMutex; // rbx
  Scaleform::List<Scaleform::Render::DIQueuePage,Scaleform::Render::DIQueuePage> *v7; // rax
  Scaleform::List<Scaleform::Render::DIQueuePage,Scaleform::Render::DIQueuePage> *p_QueueList; // rdi
  Scaleform::Render::DICommandQueue *pNext; // rdx
  Scaleform::Render::DIQueuePage *pPrev; // rcx
  Scaleform::List<Scaleform::Render::DIQueuePage,Scaleform::Render::DIQueuePage> *v11; // rax
  Scaleform::Render::DICommandQueue *v12; // rdx
  Scaleform::Render::DIQueuePage *v13; // rcx
  Scaleform::List<Scaleform::Render::DIQueuePage,Scaleform::Render::DIQueuePage> *Queues; // rax
  Scaleform::Render::DICommandQueue *v15; // rdx
  Scaleform::Render::DIQueuePage *v16; // rcx

  p_CommandSetMutex = &this->CommandSetMutex;
  Scaleform::Mutex::DoLock(&this->CommandSetMutex);
  v7 = &this->Queues[2];
  p_QueueList = &cmdSet->QueueList;
  pNext = (Scaleform::Render::DICommandQueue *)this->Queues[2].Root.pNext;
  if ( pNext != (Scaleform::Render::DICommandQueue *)&this->Queues[2] )
  {
    pPrev = v7->Root.pPrev;
    v7->Root.pPrev = (Scaleform::Render::DIQueuePage *)v7;
    this->Queues[2].Root.pNext = (Scaleform::Render::DIQueuePage *)&this->Queues[2];
    pPrev->pNext = (Scaleform::Render::DIQueuePage *)p_QueueList;
    pNext->vfptr = (Scaleform::RefCountImplCoreVtbl *)p_QueueList->Root.pPrev;
    p_QueueList->Root.pPrev->pNext = (Scaleform::Render::DIQueuePage *)pNext;
    p_QueueList->Root.pPrev = pPrev;
  }
  if ( type == DICommand_All )
  {
    v11 = &this->Queues[1];
    v12 = (Scaleform::Render::DICommandQueue *)this->Queues[1].Root.pNext;
    if ( v12 != (Scaleform::Render::DICommandQueue *)&this->Queues[1] )
    {
      v13 = v11->Root.pPrev;
      v11->Root.pPrev = (Scaleform::Render::DIQueuePage *)v11;
      this->Queues[1].Root.pNext = (Scaleform::Render::DIQueuePage *)&this->Queues[1];
      v13->pNext = (Scaleform::Render::DIQueuePage *)p_QueueList;
      v12->vfptr = (Scaleform::RefCountImplCoreVtbl *)p_QueueList->Root.pPrev;
      p_QueueList->Root.pPrev->pNext = (Scaleform::Render::DIQueuePage *)v12;
      p_QueueList->Root.pPrev = v13;
    }
    Queues = this->Queues;
    v15 = (Scaleform::Render::DICommandQueue *)this->Queues[0].Root.pNext;
    if ( v15 != (Scaleform::Render::DICommandQueue *)this->Queues )
    {
      v16 = Queues->Root.pPrev;
      Queues->Root.pPrev = (Scaleform::Render::DIQueuePage *)Queues;
      this->Queues[0].Root.pNext = (Scaleform::Render::DIQueuePage *)this->Queues;
      v16->pNext = (Scaleform::Render::DIQueuePage *)p_QueueList;
      v15->vfptr = (Scaleform::RefCountImplCoreVtbl *)p_QueueList->Root.pPrev;
      p_QueueList->Root.pPrev->pNext = (Scaleform::Render::DIQueuePage *)v15;
      p_QueueList->Root.pPrev = v16;
    }
  }
  Scaleform::Mutex::Unlock(p_CommandSetMutex);
}

// File Line: 252
// RVA: 0x9CB7B0
char *__fastcall Scaleform::Render::DICommandQueue::allocCommandFromPage(
        Scaleform::Render::DICommandQueue *this,
        unsigned int size,
        Scaleform::Lock *locked)
{
  Scaleform::Render::DIQueuePage *pPrev; // r9
  __int64 Offset; // rcx
  char *result; // rax

  pPrev = this->Queues[0].Root.pPrev;
  if ( pPrev == (Scaleform::Render::DIQueuePage *)this->Queues || size > 496 - pPrev->Offset )
  {
    if ( !this->FreePageCount && this->AllocPageCount >= 0x10 )
    {
      LeaveCriticalSection(&locked->cs);
      _InterlockedExchangeAdd(&this->RefCount, 1u);
      _InterlockedExchangeAdd(&this->ExecuteCmd.pObject->RefCount, 1u);
      this->pRTCommandQueue->vfptr->PushThreadCommand(this->pRTCommandQueue, this->ExecuteCmd.pObject);
      Scaleform::Render::DICommandQueue::ExecuteCommand::WaitDoneAndReset(this->ExecuteCmd.pObject);
      EnterCriticalSection(&locked->cs);
    }
    pPrev = Scaleform::Render::DICommandQueue::allocPage(this);
  }
  if ( !pPrev )
    return 0i64;
  Offset = pPrev->Offset;
  if ( size > 496 - (int)Offset )
    return 0i64;
  result = &pPrev->Buffer[Offset];
  pPrev->Offset = size + Offset;
  return result;
}

// File Line: 274
// RVA: 0x9CD030
Scaleform::Render::DIQueuePage *__fastcall Scaleform::Render::DICommandQueue::allocPage(
        Scaleform::Render::DICommandQueue *this)
{
  Scaleform::Render::DIQueuePage *pNext; // r8
  __int64 v3; // rax
  Scaleform::Render::DIQueuePage *result; // rax
  int v5; // [rsp+48h] [rbp+10h] BYREF
  __int64 v6; // [rsp+50h] [rbp+18h]

  if ( (Scaleform::List<Scaleform::Render::DIQueuePage,Scaleform::Render::DIQueuePage> *)this->Queues[3].Root.pNext == &this->Queues[3] )
  {
    v5 = 2;
    v3 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::DICommandQueue *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
           Scaleform::Memory::pGlobalHeap,
           this,
           520i64,
           &v5,
           -2i64);
    pNext = (Scaleform::Render::DIQueuePage *)v3;
    v6 = v3;
    if ( v3 )
      *(_QWORD *)(v3 + 512) = 0i64;
    else
      pNext = 0i64;
  }
  else
  {
    pNext = this->Queues[3].Root.pNext;
    pNext->pPrev->pNext = pNext->pNext;
    pNext->pNext->Scaleform::ListNode<Scaleform::Render::DIQueuePage>::$44454289C2DA0525B3C059BFF249C3BE::pPrev = pNext->pPrev;
    pNext->pPrev = (Scaleform::Render::DIQueuePage *)-1i64;
    pNext->pNext = (Scaleform::Render::DIQueuePage *)-1i64;
    --this->FreePageCount;
  }
  result = pNext;
  if ( pNext )
  {
    pNext->pPrev = this->Queues[0].Root.pPrev;
    pNext->pNext = (Scaleform::Render::DIQueuePage *)this->Queues;
    this->Queues[0].Root.pPrev->pNext = pNext;
    this->Queues[0].Root.pPrev = pNext;
  }
  return result;
}

// File Line: 326
// RVA: 0x9F8B70
void __fastcall Scaleform::Render::DICommandQueue::updateCPUModifiedImagesRT(Scaleform::Render::DICommandQueue *this)
{
  Scaleform::Lock *p_QueueLock; // rsi
  Scaleform::Render::DrawableImage *v3; // rdi
  Scaleform::Render::DrawableImage *pObject; // rcx
  Scaleform::Render::DrawableImage *v5; // rbx
  Scaleform::Render::DrawableImage *v6; // rcx
  Scaleform::Render::DrawableImage *v7; // rdi
  bool v8; // zf
  Scaleform::Render::DrawableImage *v9; // [rsp+60h] [rbp+8h]
  Scaleform::Lock *v10; // [rsp+70h] [rbp+18h]

  p_QueueLock = &this->QueueLock;
  v10 = &this->QueueLock;
  EnterCriticalSection(&this->QueueLock.cs);
  v3 = 0i64;
  pObject = this->pCPUModifiedImageList.pObject;
  if ( pObject )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))pObject->vfptr[1].__vecDelDtor)(pObject);
  v5 = this->pCPUModifiedImageList.pObject;
  if ( v5 )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v5->vfptr[2].__vecDelDtor)(v5);
  this->pCPUModifiedImageList.pObject = 0i64;
  if ( v5 )
  {
    do
    {
      if ( v5 )
        ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v5->vfptr[1].__vecDelDtor)(v5);
      if ( v3 )
        ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v3->vfptr[2].__vecDelDtor)(v3);
      v9 = v5;
      Scaleform::Render::DrawableImage::updateRenderTargetRT(v5);
      v6 = v5->pCPUModifiedNext.pObject;
      if ( v6 )
        ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v6->vfptr[1].__vecDelDtor)(v6);
      if ( v5 )
        ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v5->vfptr[2].__vecDelDtor)(v5);
      v7 = v5->pCPUModifiedNext.pObject;
      if ( v7 )
        ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v7->vfptr[2].__vecDelDtor)(v5->pCPUModifiedNext.pObject);
      v5->pCPUModifiedNext.pObject = 0i64;
      v5->DrawableImageState &= ~8u;
      v5 = v7;
      v8 = v7 == 0i64;
      v3 = v9;
    }
    while ( !v8 );
    p_QueueLock = v10;
  }
  if ( v5 )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v5->vfptr[2].__vecDelDtor)(v5);
  if ( v3 )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v3->vfptr[2].__vecDelDtor)(v3);
  LeaveCriticalSection(&p_QueueLock->cs);
}

// File Line: 348
// RVA: 0x9F9D40
void __fastcall Scaleform::Render::DICommandQueue::updateGPUModifiedImagesRT(Scaleform::Render::DICommandQueue *this)
{
  Scaleform::Lock *p_QueueLock; // rsi
  Scaleform::Render::DrawableImage *v3; // rdi
  Scaleform::Render::DrawableImage *pObject; // rcx
  Scaleform::Render::DrawableImage *v5; // rbx
  Scaleform::Render::DrawableImage *v6; // rcx
  Scaleform::Render::DrawableImage *v7; // rdi
  bool v8; // zf
  Scaleform::Render::DrawableImage *v9; // [rsp+60h] [rbp+8h]
  Scaleform::Lock *v10; // [rsp+70h] [rbp+18h]

  p_QueueLock = &this->QueueLock;
  v10 = &this->QueueLock;
  EnterCriticalSection(&this->QueueLock.cs);
  v3 = 0i64;
  pObject = this->pGPUModifiedImageList.pObject;
  if ( pObject )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))pObject->vfptr[1].__vecDelDtor)(pObject);
  v5 = this->pGPUModifiedImageList.pObject;
  if ( v5 )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v5->vfptr[2].__vecDelDtor)(v5);
  this->pGPUModifiedImageList.pObject = 0i64;
  if ( v5 )
  {
    do
    {
      if ( v5 )
        ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v5->vfptr[1].__vecDelDtor)(v5);
      if ( v3 )
        ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v3->vfptr[2].__vecDelDtor)(v3);
      v9 = v5;
      Scaleform::Render::DrawableImage::updateStagingTargetRT(v5);
      v6 = v5->pGPUModifiedNext.pObject;
      if ( v6 )
        ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v6->vfptr[1].__vecDelDtor)(v6);
      if ( v5 )
        ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v5->vfptr[2].__vecDelDtor)(v5);
      v7 = v5->pGPUModifiedNext.pObject;
      if ( v7 )
        ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v7->vfptr[2].__vecDelDtor)(v5->pGPUModifiedNext.pObject);
      v5->pGPUModifiedNext.pObject = 0i64;
      v5->DrawableImageState &= ~0x10u;
      v5 = v7;
      v8 = v7 == 0i64;
      v3 = v9;
    }
    while ( !v8 );
    p_QueueLock = v10;
  }
  if ( v5 )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v5->vfptr[2].__vecDelDtor)(v5);
  if ( v3 )
    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v3->vfptr[2].__vecDelDtor)(v3);
  LeaveCriticalSection(&p_QueueLock->cs);
}

// File Line: 371
// RVA: 0x99C900
void __fastcall Scaleform::Render::DICommandQueue::OnCapture(Scaleform::Render::DICommandQueue *this)
{
  Scaleform::Mutex *p_CommandSetMutex; // rbx
  Scaleform::Lock *p_QueueLock; // rdi
  Scaleform::List<Scaleform::Render::DIQueuePage,Scaleform::Render::DIQueuePage> *Queues; // rax
  Scaleform::List<Scaleform::Render::DIQueuePage,Scaleform::Render::DIQueuePage> *v5; // rsi
  Scaleform::Render::DIQueuePage *pNext; // rdx
  Scaleform::Render::DIQueuePage *pPrev; // rcx

  p_CommandSetMutex = &this->CommandSetMutex;
  Scaleform::Mutex::DoLock(&this->CommandSetMutex);
  while ( this->pRTCommands )
    Scaleform::WaitCondition::Wait(&this->CommandSetWC, p_CommandSetMutex, 0xFFFFFFFF);
  p_QueueLock = &this->QueueLock;
  EnterCriticalSection(&this->QueueLock.cs);
  Queues = this->Queues;
  v5 = &this->Queues[1];
  pNext = Queues->Root.pNext;
  if ( pNext != (Scaleform::Render::DIQueuePage *)Queues )
  {
    pPrev = Queues->Root.pPrev;
    Queues->Root.pPrev = (Scaleform::Render::DIQueuePage *)Queues;
    Queues->Root.pNext = (Scaleform::Render::DIQueuePage *)Queues;
    pPrev->pNext = (Scaleform::Render::DIQueuePage *)v5;
    pNext->pPrev = v5->Root.pPrev;
    v5->Root.pPrev->pNext = pNext;
    v5->Root.pPrev = pPrev;
  }
  LeaveCriticalSection(&p_QueueLock->cs);
  Scaleform::Mutex::Unlock(p_CommandSetMutex);
}

// File Line: 403
// RVA: 0x9741E0
void __fastcall Scaleform::Render::DICommandQueue::ExecuteNextCapture(
        Scaleform::Render::DICommandQueue *this,
        Scaleform::Render::ContextImpl::RenderNotify *pnotify)
{
  Scaleform::Render::ThreadCommandQueue *pRTCommandQueue; // rcx
  Scaleform::List<Scaleform::Render::DIQueuePage,Scaleform::Render::DIQueuePage> *v4; // rax
  Scaleform::List<Scaleform::Render::DIQueuePage,Scaleform::Render::DIQueuePage> *v5; // r14
  Scaleform::Render::DICommandQueue *pNext; // rdx
  Scaleform::Render::DIQueuePage *pPrev; // rcx
  Scaleform::Render::DIQueuePage *v8; // rdx
  Scaleform::Render::DIQueuePage *v9; // rcx
  Scaleform::Render::DICommandContext context; // [rsp+28h] [rbp-48h] BYREF
  Scaleform::Render::DICommandSet v11; // [rsp+38h] [rbp-38h] BYREF
  __int64 v12; // [rsp+50h] [rbp-20h] BYREF
  Scaleform::Render::HAL *v13; // [rsp+58h] [rbp-18h]
  Scaleform::Render::Renderer2D *v14; // [rsp+60h] [rbp-10h]
  __int64 v15; // [rsp+68h] [rbp-8h]

  if ( !this->pRTCommandQueue && pnotify )
    this->pRTCommandQueue = pnotify->pRTCommandQueue;
  pRTCommandQueue = this->pRTCommandQueue;
  v12 = 0i64;
  v13 = 0i64;
  v14 = 0i64;
  v15 = 0i64;
  if ( pRTCommandQueue )
  {
    pRTCommandQueue->vfptr->GetRenderInterfaces(pRTCommandQueue, (Scaleform::Render::Interfaces *)&v12);
    context.pR2D = v14;
    context.pHAL = v13;
  }
  v11.pQueue = this;
  v11.QueueList.Root.pPrev = (Scaleform::Render::DIQueuePage *)&v11.QueueList;
  v11.QueueList.Root.pNext = (Scaleform::Render::DIQueuePage *)&v11.QueueList;
  Scaleform::Mutex::DoLock(&this->CommandSetMutex);
  EnterCriticalSection(&this->QueueLock.cs);
  v4 = &this->Queues[1];
  v5 = &this->Queues[2];
  pNext = (Scaleform::Render::DICommandQueue *)this->Queues[1].Root.pNext;
  if ( pNext != (Scaleform::Render::DICommandQueue *)&this->Queues[1] )
  {
    pPrev = v4->Root.pPrev;
    v4->Root.pPrev = (Scaleform::Render::DIQueuePage *)v4;
    this->Queues[1].Root.pNext = (Scaleform::Render::DIQueuePage *)&this->Queues[1];
    pPrev->pNext = (Scaleform::Render::DIQueuePage *)v5;
    pNext->vfptr = (Scaleform::RefCountImplCoreVtbl *)v5->Root.pPrev;
    v5->Root.pPrev->pNext = (Scaleform::Render::DIQueuePage *)pNext;
    v5->Root.pPrev = pPrev;
  }
  Scaleform::Mutex::DoLock(&this->CommandSetMutex);
  v8 = this->Queues[2].Root.pNext;
  if ( v8 != (Scaleform::Render::DIQueuePage *)v5 )
  {
    v9 = v5->Root.pPrev;
    v5->Root.pPrev = (Scaleform::Render::DIQueuePage *)v5;
    this->Queues[2].Root.pNext = (Scaleform::Render::DIQueuePage *)&this->Queues[2];
    v9->pNext = (Scaleform::Render::DIQueuePage *)&v11.QueueList;
    v8->pPrev = v11.QueueList.Root.pPrev;
    v11.QueueList.Root.pPrev->pNext = v8;
    v11.QueueList.Root.pPrev = v9;
  }
  Scaleform::Mutex::Unlock(&this->CommandSetMutex);
  this->pRTCommands = &v11;
  LeaveCriticalSection(&this->QueueLock.cs);
  Scaleform::Mutex::Unlock(&this->CommandSetMutex);
  Scaleform::Render::DICommandSet::ExecuteCommandsRT(&v11, (unsigned __int64)&context);
  Scaleform::Mutex::DoLock(&this->CommandSetMutex);
  this->pRTCommands = 0i64;
  Scaleform::WaitCondition::NotifyAll(&this->CommandSetWC);
  Scaleform::Mutex::Unlock(&this->CommandSetMutex);
}

// File Line: 451
// RVA: 0x96E350
void __fastcall Scaleform::Render::DICommandQueue::DiscardCommands(Scaleform::Render::DICommandQueue *this)
{
  Scaleform::Render::DIQueuePage *i; // rbx
  char *Buffer; // rsi
  char *v3; // rdi
  Scaleform::Render::DICommandSet cmdSet; // [rsp+20h] [rbp-28h] BYREF

  cmdSet.QueueList.Root.pPrev = (Scaleform::Render::DIQueuePage *)&cmdSet.QueueList;
  cmdSet.pQueue = this;
  cmdSet.QueueList.Root.pNext = (Scaleform::Render::DIQueuePage *)&cmdSet.QueueList;
  Scaleform::Render::DICommandQueue::popCommandSet(this, &cmdSet, DICommand_All);
  for ( i = cmdSet.QueueList.Root.pNext;
        (Scaleform::List<Scaleform::Render::DIQueuePage,Scaleform::Render::DIQueuePage> *)cmdSet.QueueList.Root.pNext != &cmdSet.QueueList;
        i = cmdSet.QueueList.Root.pNext )
  {
    i->pPrev->pNext = i->pNext;
    i->pNext->Scaleform::ListNode<Scaleform::Render::DIQueuePage>::$44454289C2DA0525B3C059BFF249C3BE::pPrev = i->pPrev;
    i->pPrev = (Scaleform::Render::DIQueuePage *)-1i64;
    i->pNext = (Scaleform::Render::DIQueuePage *)-1i64;
    if ( i->Offset )
    {
      Buffer = i->Buffer;
      if ( i != (Scaleform::Render::DIQueuePage *)-16i64 )
      {
        do
        {
          (*(void (__fastcall **)(char *))(*(_QWORD *)Buffer + 64i64))(Buffer);
          v3 = &Buffer[(*(unsigned int (__fastcall **)(char *))(*(_QWORD *)Buffer + 32i64))(Buffer)];
          if ( v3 >= &i->Buffer[i->Offset] )
            v3 = 0i64;
          (**(void (__fastcall ***)(char *, _QWORD))Buffer)(Buffer, 0i64);
          Buffer = v3;
        }
        while ( v3 );
      }
    }
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, i);
  }
}

// File Line: 472
// RVA: 0x971E30
void __fastcall Scaleform::Render::DICommandQueue::ExecuteCommand::Execute(
        Scaleform::Render::DICommandQueue::ExecuteCommand *this)
{
  Scaleform::Render::ThreadCommandQueue *pRTCommandQueue; // rcx
  Scaleform::Mutex *p_CommandSetMutex; // rbx
  Scaleform::Render::DICommandQueue *pQueue; // rcx
  Scaleform::Render::DICommandContext context; // [rsp+28h] [rbp-50h] BYREF
  Scaleform::Render::DICommandSet cmdSet; // [rsp+38h] [rbp-40h] BYREF
  __int64 v7; // [rsp+50h] [rbp-28h] BYREF
  Scaleform::Render::HAL *v8; // [rsp+58h] [rbp-20h]
  Scaleform::Render::Renderer2D *v9; // [rsp+60h] [rbp-18h]
  __int64 v10; // [rsp+68h] [rbp-10h]

  pRTCommandQueue = this->pQueue->pRTCommandQueue;
  v7 = 0i64;
  v8 = 0i64;
  v9 = 0i64;
  v10 = 0i64;
  if ( pRTCommandQueue )
  {
    pRTCommandQueue->vfptr->GetRenderInterfaces(pRTCommandQueue, (Scaleform::Render::Interfaces *)&v7);
    context.pR2D = v9;
    context.pHAL = v8;
  }
  cmdSet.pQueue = this->pQueue;
  cmdSet.QueueList.Root.pPrev = (Scaleform::Render::DIQueuePage *)&cmdSet.QueueList;
  cmdSet.QueueList.Root.pNext = (Scaleform::Render::DIQueuePage *)&cmdSet.QueueList;
  Scaleform::Render::DICommandQueue::popCommandSet(cmdSet.pQueue, &cmdSet, DICommand_All);
  this->pQueue->pRTCommands = &cmdSet;
  Scaleform::Render::DICommandSet::ExecuteCommandsRT(&cmdSet, &context);
  p_CommandSetMutex = &this->pQueue->CommandSetMutex;
  Scaleform::Mutex::DoLock(p_CommandSetMutex);
  this->pQueue->pRTCommands = 0i64;
  Scaleform::WaitCondition::NotifyAll(&this->pQueue->CommandSetWC);
  Scaleform::Mutex::Unlock(p_CommandSetMutex);
  pQueue = this->pQueue;
  if ( !_InterlockedDecrement(&pQueue->RefCount) && pQueue )
    pQueue->vfptr->__vecDelDtor(pQueue, 1u);
  Scaleform::Event::SetEvent(&this->ExecuteDone);
  if ( !_InterlockedDecrement(&this->RefCount) )
    this->vfptr->__vecDelDtor(this, 1i64);
}

// File Line: 545
// RVA: 0x971F60
void __fastcall Scaleform::Render::DICommandSet::ExecuteCommandsRT(
        Scaleform::Render::DICommandSet *this,
        unsigned __int64 context)
{
  Scaleform::Render::DICommandSet *v2; // r13
  Scaleform::Render::HAL *v3; // r12
  char v4; // di
  char v5; // bl
  char v6; // si
  Scaleform::List<Scaleform::Render::DIQueuePage,Scaleform::Render::DIQueuePage> *p_QueueList; // rax
  __int64 v8; // r8
  __int64 pNext; // r14
  __int64 v10; // rax
  Scaleform::Render::DICommand *v11; // r15
  Scaleform::Render::DrawableImage *v12; // rbx
  char v13; // si
  Scaleform::Render::DrawableImage *pObject; // r13
  char v15; // al
  bool v16; // r14
  Scaleform::Render::DICommand *v17; // rdi
  int *v18; // rax
  float v19; // xmm1_4
  float v20; // xmm0_4
  Scaleform::RefCountImplCoreVtbl *vfptr; // rdi
  __int64 v22; // rax
  int v23; // r15d
  int v24; // esi
  int v25; // r14d
  int v26; // edi
  int *v27; // rax
  int v28; // r15d
  int v29; // ecx
  int v30; // eax
  Scaleform::Render::RenderSync *v31; // rax
  Scaleform::Render::Fence *inserted; // rax
  __int64 v33; // rdx
  Scaleform::Render::Fence *v34; // rsi
  Scaleform::Render::FenceImpl *Data; // rcx
  Scaleform::Render::RenderSync *RSContext; // rdi
  Scaleform::Render::FenceImpl *v38; // rcx
  __int64 v39; // rax
  __int64 v40; // rax
  int *v41; // rax
  float v42; // xmm1_4
  float v43; // xmm0_4
  Scaleform::RefCountImplCoreVtbl *v44; // rdi
  __int64 v45; // rax
  int v46; // r15d
  int v47; // esi
  Scaleform::Render::DICommand *v48; // rdi
  Scaleform::Render::RenderSync *v49; // rax
  Scaleform::Render::Fence *v50; // rax
  Scaleform::Render::Fence *v51; // rdi
  Scaleform::Render::Fence *v52; // rcx
  __int64 v53; // rax
  Scaleform::Render::DICommandQueue *pQueue; // rdx
  char v55; // [rsp+30h] [rbp-A9h]
  char v56; // [rsp+31h] [rbp-A8h]
  unsigned __int8 v57; // [rsp+32h] [rbp-A7h]
  Scaleform::Render::Color backgroundColor; // [rsp+34h] [rbp-A5h] BYREF
  Scaleform::Render::DICommand *v59; // [rsp+38h] [rbp-A1h]
  __int64 v60; // [rsp+40h] [rbp-99h] BYREF
  float v61; // [rsp+48h] [rbp-91h]
  float v62; // [rsp+4Ch] [rbp-8Dh]
  __int64 v63; // [rsp+50h] [rbp-89h] BYREF
  float v64; // [rsp+58h] [rbp-81h]
  float v65; // [rsp+5Ch] [rbp-7Dh]
  Scaleform::Render::Viewport vpin; // [rsp+60h] [rbp-79h] BYREF
  Scaleform::Render::DrawableImage *v67; // [rsp+90h] [rbp-49h]
  __int64 v68; // [rsp+98h] [rbp-41h]
  __int64 v69[2]; // [rsp+A0h] [rbp-39h] BYREF
  __int64 v70[3]; // [rsp+B0h] [rbp-29h] BYREF
  char v71[8]; // [rsp+C8h] [rbp-11h] BYREF
  __int64 v72; // [rsp+D0h] [rbp-9h]
  char v73[8]; // [rsp+D8h] [rbp-1h] BYREF
  char v74[8]; // [rsp+E0h] [rbp+7h] BYREF
  char v75[72]; // [rsp+E8h] [rbp+Fh] BYREF
  Scaleform::Render::DICommandContext *contexta; // [rsp+148h] [rbp+6Fh]
  char v78; // [rsp+150h] [rbp+77h]
  Scaleform::Render::Fence *v79; // [rsp+158h] [rbp+7Fh] BYREF

  contexta = (Scaleform::Render::DICommandContext *)context;
  v72 = -2i64;
  v2 = this;
  v3 = *(Scaleform::Render::HAL **)(context + 8);
  LOBYTE(context) = 0;
  v57 = 0;
  v4 = 0;
  v78 = 0;
  v5 = 1;
  v56 = 1;
  v6 = 0;
  v55 = 0;
  p_QueueList = &this->QueueList;
  if ( (Scaleform::List<Scaleform::Render::DIQueuePage,Scaleform::Render::DIQueuePage> *)this->QueueList.Root.pNext != &this->QueueList )
  {
    v8 = 0i64;
    do
    {
      pNext = (__int64)v2->QueueList.Root.pNext;
      v68 = pNext;
      *(_QWORD *)(*(_QWORD *)pNext + 8i64) = *(_QWORD *)(pNext + 8);
      **(_QWORD **)(pNext + 8) = *(_QWORD *)pNext;
      *(_QWORD *)pNext = -1i64;
      *(_QWORD *)(pNext + 8) = -1i64;
      if ( !(_BYTE)context )
      {
        v10 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *, __int64, _QWORD))v3->vfptr[60].__vecDelDtor)(
                v3,
                15i64,
                0i64);
        (*(void (__fastcall **)(__int64, const char *))(*(_QWORD *)v10 + 16i64))(
          v10,
          "Scaleform::Render::DrawableImage");
        v57 = 1;
        v8 = 0i64;
      }
      v11 = (Scaleform::Render::DICommand *)(pNext + 16);
      if ( !*(_DWORD *)(pNext + 512) )
        v11 = 0i64;
      v59 = v11;
      v12 = 0i64;
      v67 = 0i64;
      v13 = 0;
      LOBYTE(v79) = 0;
      if ( v11 )
      {
        while ( 1 )
        {
          pObject = v11->pImage.pObject;
          if ( pObject )
            ((void (__fastcall *)(Scaleform::Render::DrawableImage *, unsigned __int64, __int64))pObject->vfptr[1].__vecDelDtor)(
              v11->pImage.pObject,
              context,
              v8);
          v70[2] = (__int64)pObject;
          v15 = ((__int64 (__fastcall *)(Scaleform::Render::DICommand *, unsigned __int64, __int64))v11->vfptr->GetRenderCaps)(
                  v11,
                  context,
                  v8);
          if ( v12 == pObject && v12 && v13 )
          {
            v16 = (v15 & 2) != 0;
            if ( (v15 & 2) == 0 )
              goto LABEL_31;
          }
          else
          {
            if ( (v15 & 4) == 0 && (v15 & 1) != 0 || (v15 & 8) != 0 )
            {
              v16 = 0;
LABEL_31:
              if ( (!v12 || !v13) && v16 )
              {
                if ( !v4 )
                {
                  if ( (v3->HALState & 4) != 0 )
                  {
                    v55 = 1;
                    ((void (__fastcall *)(Scaleform::Render::HAL *))v3->vfptr[10].__vecDelDtor)(v3);
                  }
                  if ( (v3->HALState & 2) == 0 )
                  {
                    ((void (__fastcall *)(Scaleform::Render::HAL *))v3->vfptr[5].__vecDelDtor)(v3);
                    v56 = 0;
                  }
                  v78 = 1;
                }
                if ( pObject )
                  ((void (__fastcall *)(Scaleform::Render::DrawableImage *))pObject->vfptr[1].__vecDelDtor)(pObject);
                if ( v12 )
                  ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v12->vfptr[2].__vecDelDtor)(v12);
                v12 = pObject;
                v67 = pObject;
                v18 = (int *)pObject->vfptr[5].__vecDelDtor(pObject, (unsigned int)v74);
                v19 = (float)v18[1];
                v20 = (float)*v18;
                v60 = 0i64;
                v61 = v20;
                v62 = v19;
                LODWORD(v79) = 0;
                vfptr = v3->vfptr;
                v22 = ((__int64 (__fastcall *)(Scaleform::Render::DrawableImage *))pObject->vfptr[26].__vecDelDtor)(pObject);
                ((void (__fastcall *)(Scaleform::Render::HAL *, __int64 *, __int64, __int64, Scaleform::Render::Fence **))vfptr[24].__vecDelDtor)(
                  v3,
                  &v60,
                  v22,
                  3i64,
                  &v79);
                LOBYTE(v79) = 1;
                ((void (__fastcall *)(Scaleform::Render::HAL *))v3->vfptr[9].__vecDelDtor)(v3);
                v23 = (int)v62;
                v24 = (int)v61;
                v25 = (int)*((float *)&v60 + 1);
                v26 = (int)*(float *)&v60;
                v27 = (int *)pObject->vfptr[5].__vecDelDtor(pObject, (unsigned int)v71);
                vpin.Width = v24 - v26;
                v28 = v23 - v25;
                vpin.Flags = 1;
                *(_QWORD *)&vpin.ScissorWidth = 0i64;
                *(_QWORD *)&vpin.ScissorLeft = 0i64;
                goto LABEL_45;
              }
              if ( v12 != pObject )
              {
                if ( v13 )
                {
                  if ( pObject )
                    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))pObject->vfptr[1].__vecDelDtor)(pObject);
                  if ( v12 )
                    ((void (__fastcall *)(Scaleform::Render::DrawableImage *))v12->vfptr[2].__vecDelDtor)(v12);
                  v12 = pObject;
                  v67 = pObject;
                  if ( (v3->HALState & 0x400) != 0 )
                  {
                    ((void (__fastcall *)(Scaleform::Render::HAL *))v3->vfptr[8].__vecDelDtor)(v3);
                    ((void (__fastcall *)(Scaleform::Render::HAL *))v3->vfptr[12].__vecDelDtor)(v3);
                  }
                  else
                  {
                    v69[0] = (__int64)&Scaleform::Render::HALEndDisplayItem::Instance;
                    v69[1] = 0i64;
                    v3->vfptr[33].__vecDelDtor(v3, (unsigned int)v69);
                  }
                  ((void (__fastcall *)(Scaleform::Render::HAL *))v3->vfptr[10].__vecDelDtor)(v3);
                  Scaleform::Render::DICommandQueue::updateCPUModifiedImagesRT(this->pQueue);
                  v3->vfptr[25].__vecDelDtor(v3, 2u);
                  if ( ((__int64 (__fastcall *)(Scaleform::Render::HAL *))contexta->pHAL->vfptr[65].__vecDelDtor)(contexta->pHAL) )
                  {
                    v31 = (Scaleform::Render::RenderSync *)((__int64 (__fastcall *)(Scaleform::Render::HAL *))contexta->pHAL->vfptr[65].__vecDelDtor)(contexta->pHAL);
                    inserted = Scaleform::Render::RenderSync::InsertFence(v31);
                    v33 = (__int64)inserted;
                    v79 = inserted;
                    if ( inserted )
                      ++inserted->RefCount;
                    v34 = pObject->pFence.pObject;
                    if ( v34 )
                    {
                      if ( v34->RefCount-- == 1 )
                      {
                        Data = v34->Data;
                        if ( v34->HasData )
                        {
                          RSContext = Data->RSContext;
                          ((void (__fastcall *)(Scaleform::Render::FenceImpl *, unsigned __int64))Data->RSContext->FenceFrameAlloc.pHeapOrPtr)(
                            Data,
                            Data->APIHandle);
                          v38 = v34->Data;
                          v38->RSContext = (Scaleform::Render::RenderSync *)RSContext->FenceImplAlloc.FirstEmptySlot;
                          RSContext->FenceImplAlloc.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> >::NodeType *)v38;
                          v34->Data = (Scaleform::Render::FenceImpl *)RSContext->FenceAlloc.FirstEmptySlot;
                          RSContext->FenceAlloc.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> >::NodeType *)v34;
                          v33 = (__int64)v79;
                        }
                        else
                        {
                          v34->Data = (Scaleform::Render::FenceImpl *)Data[4].Parent;
                          Data[4].Parent = (Scaleform::Render::FenceFrame *)v34;
                        }
                      }
                    }
                    pObject->pFence.pObject = (Scaleform::Render::Fence *)v33;
                  }
                  LOBYTE(v79) = 0;
                }
                v39 = (__int64)v3->vfptr[60].__vecDelDtor(v3, 15u);
                (*(void (__fastcall **)(__int64))(*(_QWORD *)v39 + 24i64))(v39);
                v40 = (__int64)v3->vfptr[60].__vecDelDtor(v3, 15u);
                (*(void (__fastcall **)(__int64, const char *))(*(_QWORD *)v40 + 16i64))(
                  v40,
                  "Scaleform::Render::DrawableImage");
                if ( v16 )
                {
                  if ( !v78 )
                  {
                    if ( (v3->HALState & 4) != 0 )
                    {
                      v55 = 1;
                      ((void (__fastcall *)(Scaleform::Render::HAL *))v3->vfptr[10].__vecDelDtor)(v3);
                    }
                    if ( (v3->HALState & 2) == 0 )
                    {
                      ((void (__fastcall *)(Scaleform::Render::HAL *))v3->vfptr[5].__vecDelDtor)(v3);
                      v56 = 0;
                    }
                    v78 = 1;
                  }
                  v41 = (int *)v12->vfptr[5].__vecDelDtor(v12, (unsigned int)v73);
                  v42 = (float)v41[1];
                  v43 = (float)*v41;
                  v63 = 0i64;
                  v64 = v43;
                  v65 = v42;
                  LODWORD(v79) = 0;
                  v44 = v3->vfptr;
                  v45 = ((__int64 (__fastcall *)(Scaleform::Render::DrawableImage *))v12->vfptr[26].__vecDelDtor)(v12);
                  ((void (__fastcall *)(Scaleform::Render::HAL *, __int64 *, __int64, __int64, Scaleform::Render::Fence **))v44[24].__vecDelDtor)(
                    v3,
                    &v63,
                    v45,
                    3i64,
                    &v79);
                  LOBYTE(v79) = 1;
                  ((void (__fastcall *)(Scaleform::Render::HAL *))v3->vfptr[9].__vecDelDtor)(v3);
                  v46 = (int)v65;
                  v47 = (int)v64;
                  v25 = (int)*((float *)&v63 + 1);
                  v26 = (int)*(float *)&v63;
                  v27 = (int *)v12->vfptr[5].__vecDelDtor(v12, (unsigned int)v75);
                  vpin.Width = v47 - v26;
                  v28 = v46 - v25;
                  memset(&vpin.ScissorLeft, 0, 20);
LABEL_45:
                  v29 = v27[1];
                  v30 = *v27;
                  vpin.Height = v28;
                  vpin.Top = v25;
                  vpin.Left = v26;
                  vpin.BufferHeight = v29;
                  vpin.BufferWidth = v30;
                  backgroundColor = 0;
                  Scaleform::Render::HAL::BeginDisplay(v3, (int *)&backgroundColor.Raw, &vpin);
                  v11 = v59;
                }
              }
              Scaleform::Render::DICommand::ExecuteRT(v11, contexta);
              v48 = (Scaleform::Render::DICommand *)((char *)v11 + v11->vfptr->GetSize(v11));
              pNext = v68;
              if ( (unsigned __int64)v48 >= (unsigned __int64)*(unsigned int *)(v68 + 512) + v68 + 16 )
                v48 = 0i64;
              v11->vfptr->__vecDelDtor(v11, 0);
              v11 = v48;
              v59 = v48;
              if ( pObject )
                ((void (__fastcall *)(Scaleform::Render::DrawableImage *))pObject->vfptr[2].__vecDelDtor)(pObject);
              v13 = (char)v79;
              goto LABEL_78;
            }
            v16 = 1;
          }
          if ( pObject->pRT.pObject )
            goto LABEL_31;
          if ( !v4 )
          {
            if ( (v3->HALState & 4) != 0 )
            {
              v55 = 1;
              ((void (__fastcall *)(Scaleform::Render::HAL *))v3->vfptr[10].__vecDelDtor)(v3);
            }
            if ( (v3->HALState & 2) == 0 )
            {
              ((void (__fastcall *)(Scaleform::Render::HAL *))v3->vfptr[5].__vecDelDtor)(v3);
              v56 = 0;
            }
            v4 = 1;
            v78 = 1;
          }
          if ( Scaleform::Render::DrawableImage::ensureRenderableRT(pObject) )
            goto LABEL_31;
          v17 = (Scaleform::Render::DICommand *)((char *)v11 + v11->vfptr->GetSize(v11));
          pNext = v68;
          if ( (unsigned __int64)v17 >= (unsigned __int64)*(unsigned int *)(v68 + 512) + v68 + 16 )
            v17 = 0i64;
          v11->vfptr->__vecDelDtor(v11, 0);
          v11 = v17;
          v59 = v17;
          ((void (__fastcall *)(Scaleform::Render::DrawableImage *))pObject->vfptr[2].__vecDelDtor)(pObject);
LABEL_78:
          v4 = v78;
          if ( !v11 )
          {
            if ( v12 && v13 )
            {
              if ( (v3->HALState & 0x400) != 0 )
              {
                ((void (__fastcall *)(Scaleform::Render::HAL *))v3->vfptr[8].__vecDelDtor)(v3);
                ((void (__fastcall *)(Scaleform::Render::HAL *))v3->vfptr[12].__vecDelDtor)(v3);
              }
              else
              {
                v70[0] = (__int64)&Scaleform::Render::HALEndDisplayItem::Instance;
                v70[1] = 0i64;
                v3->vfptr[33].__vecDelDtor(v3, (unsigned int)v70);
              }
              ((void (__fastcall *)(Scaleform::Render::HAL *))v3->vfptr[10].__vecDelDtor)(v3);
              v2 = this;
              Scaleform::Render::DICommandQueue::updateCPUModifiedImagesRT(this->pQueue);
              v3->vfptr[25].__vecDelDtor(v3, 2u);
              if ( ((__int64 (__fastcall *)(Scaleform::Render::HAL *))contexta->pHAL->vfptr[65].__vecDelDtor)(contexta->pHAL) )
              {
                v49 = (Scaleform::Render::RenderSync *)((__int64 (__fastcall *)(Scaleform::Render::HAL *))contexta->pHAL->vfptr[65].__vecDelDtor)(contexta->pHAL);
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
              v2 = this;
            }
            v4 = v78;
            break;
          }
        }
      }
      if ( v57 )
      {
        v53 = ((__int64 (__fastcall *)(Scaleform::Render::HAL *, __int64, __int64))v3->vfptr[60].__vecDelDtor)(
                v3,
                15i64,
                v8);
        (*(void (__fastcall **)(__int64))(*(_QWORD *)v53 + 24i64))(v53);
      }
      pQueue = v2->pQueue;
      if ( v2->pQueue->FreePageCount >= 3 )
      {
        ((void (__fastcall *)(Scaleform::MemoryHeap *, __int64, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          pNext,
          v8);
      }
      else
      {
        *(_DWORD *)(pNext + 512) = 0;
        *(_QWORD *)pNext = pQueue->Queues[3].Root.pPrev;
        *(_QWORD *)(pNext + 8) = &pQueue->Queues[3];
        pQueue->Queues[3].Root.pPrev->pNext = (Scaleform::Render::DIQueuePage *)pNext;
        pQueue->Queues[3].Root.pPrev = (Scaleform::Render::DIQueuePage *)pNext;
        ++pQueue->FreePageCount;
      }
      if ( v12 )
        ((void (__fastcall *)(Scaleform::Render::DrawableImage *, Scaleform::Render::DICommandQueue *, __int64))v12->vfptr[2].__vecDelDtor)(
          v12,
          pQueue,
          v8);
      p_QueueList = &v2->QueueList;
      context = v57;
      v8 = 0i64;
    }
    while ( (Scaleform::List<Scaleform::Render::DIQueuePage,Scaleform::Render::DIQueuePage> *)v2->QueueList.Root.pNext != &v2->QueueList );
    v5 = v56;
    v6 = v55;
  }
  p_QueueList->Root.pPrev = (Scaleform::Render::DIQueuePage *)p_QueueList;
  p_QueueList->Root.pNext = (Scaleform::Render::DIQueuePage *)p_QueueList;
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

