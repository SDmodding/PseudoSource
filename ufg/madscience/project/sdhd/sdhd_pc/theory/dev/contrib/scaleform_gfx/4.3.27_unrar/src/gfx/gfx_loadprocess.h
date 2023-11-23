// File Line: 172
// RVA: 0x906650
void __fastcall Scaleform::GFx::LoadProcess::SetBindProcess(
        Scaleform::GFx::LoadProcess *this,
        Scaleform::GFx::Resource *pbindProcess)
{
  Scaleform::Render::RenderBuffer *pObject; // rcx

  if ( pbindProcess )
    Scaleform::Render::RenderBuffer::AddRef(pbindProcess);
  pObject = (Scaleform::Render::RenderBuffer *)this->pBindProcess.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pBindProcess.pObject = (Scaleform::GFx::MovieBindProcess *)pbindProcess;
}

// File Line: 201
// RVA: 0x8DE5F0
Scaleform::GFx::SWFProcessInfo *__fastcall Scaleform::GFx::LoadProcess::GetStream(Scaleform::GFx::LoadProcess *this)
{
  Scaleform::GFx::SWFProcessInfo *result; // rax

  result = (Scaleform::GFx::SWFProcessInfo *)this->pAltStream;
  if ( !result )
    return &this->ProcessInfo;
  return result;
}

// File Line: 209
// RVA: 0x8FDBE0
__int64 __fastcall Scaleform::GFx::LoadProcess::ReadU8(Scaleform::GFx::LoadProcess *this)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rbx
  unsigned int DataSize; // eax
  __int64 Pos; // rcx
  __int64 result; // rax

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)this->pAltStream;
  if ( !pAltStream )
    pAltStream = &this->ProcessInfo;
  DataSize = pAltStream->Stream.DataSize;
  pAltStream->Stream.UnusedBits = 0;
  if ( (int)(DataSize - pAltStream->Stream.Pos) < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 1);
  Pos = pAltStream->Stream.Pos;
  result = (unsigned __int8)pAltStream->Stream.pBuffer[Pos];
  pAltStream->Stream.Pos = Pos + 1;
  return result;
}

// File Line: 210
// RVA: 0x8FDB00
unsigned __int16 __fastcall Scaleform::GFx::LoadProcess::ReadU16(Scaleform::GFx::LoadProcess *this)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rbx
  unsigned int DataSize; // eax
  __int64 Pos; // r8
  unsigned __int16 result; // ax

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)this->pAltStream;
  if ( !pAltStream )
    pAltStream = &this->ProcessInfo;
  DataSize = pAltStream->Stream.DataSize;
  pAltStream->Stream.UnusedBits = 0;
  if ( (int)(DataSize - pAltStream->Stream.Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  result = (unsigned __int8)pAltStream->Stream.pBuffer[Pos] | ((unsigned __int8)pAltStream->Stream.pBuffer[(unsigned int)(Pos + 1)] << 8);
  pAltStream->Stream.Pos = Pos + 2;
  return result;
}

// File Line: 211
// RVA: 0x8FDB60
__int64 __fastcall Scaleform::GFx::LoadProcess::ReadU32(Scaleform::GFx::LoadProcess *this)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rbx
  unsigned int DataSize; // eax
  __int64 Pos; // r10
  char *pBuffer; // r8
  __int64 result; // rax

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)this->pAltStream;
  if ( !pAltStream )
    pAltStream = &this->ProcessInfo;
  DataSize = pAltStream->Stream.DataSize;
  pAltStream->Stream.UnusedBits = 0;
  if ( (int)(DataSize - pAltStream->Stream.Pos) < 4 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
  Pos = pAltStream->Stream.Pos;
  pBuffer = pAltStream->Stream.pBuffer;
  result = (unsigned __int8)pBuffer[Pos] | (((unsigned __int8)pBuffer[(unsigned int)(Pos + 1)] | ((((unsigned __int8)pBuffer[(unsigned int)(Pos + 3)] << 8) | (unsigned int)(unsigned __int8)pBuffer[(unsigned int)(Pos + 2)]) << 8)) << 8);
  pAltStream->Stream.Pos = Pos + 4;
  return result;
}

// File Line: 218
// RVA: 0x8E1190
Scaleform::File *__fastcall Scaleform::GFx::LoadProcess::GetUnderlyingFile(Scaleform::GFx::LoadProcess *this)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rbx
  unsigned int v2; // eax

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)this->pAltStream;
  if ( !pAltStream )
    pAltStream = &this->ProcessInfo;
  v2 = ((__int64 (__fastcall *)(Scaleform::File *, _QWORD, _QWORD))pAltStream->Stream.pInput.pObject->vfptr[14].__vecDelDtor)(
         pAltStream->Stream.pInput.pObject,
         pAltStream->Stream.FilePos + pAltStream->Stream.Pos - pAltStream->Stream.DataSize,
         0i64);
  pAltStream->Stream.ResyncFile = 1;
  if ( v2 != -1 )
  {
    pAltStream->Stream.FilePos = v2;
    *(_QWORD *)&pAltStream->Stream.Pos = 0i64;
  }
  return pAltStream->Stream.pInput.pObject;
}

// File Line: 219
// RVA: 0x8DE7D0
__int64 __fastcall Scaleform::GFx::LoadProcess::GetTagEndPosition(Scaleform::GFx::LoadProcess *this)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rdx
  __int64 v2; // rax

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)this->pAltStream;
  if ( !pAltStream )
    pAltStream = &this->ProcessInfo;
  v2 = pAltStream->Stream.TagStackEntryCount - 1;
  if ( (unsigned int)v2 >= 2 )
    return 0i64;
  else
    return (unsigned int)pAltStream->Stream.TagStack[v2];
}

// File Line: 220
// RVA: 0x912CD0
__int64 __fastcall Scaleform::GFx::LoadProcess::Tell(Scaleform::GFx::LoadProcess *this)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // rdx

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)this->pAltStream;
  if ( !pAltStream )
    pAltStream = &this->ProcessInfo;
  return pAltStream->Stream.Pos + pAltStream->Stream.FilePos - pAltStream->Stream.DataSize;
}

// File Line: 284
// RVA: 0x880FE0
Scaleform::GFx::SetBackgroundColorTag *__fastcall Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::SetBackgroundColorTag>(
        Scaleform::GFx::LoadProcess *this)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // r8
  unsigned __int64 BytesLeft; // rdx
  char *pCurrent; // rcx

  pObject = this->pLoadData.pObject;
  BytesLeft = pObject->TagMemAllocator.BytesLeft;
  if ( BytesLeft < 0x10 )
  {
    pCurrent = (char *)Scaleform::GFx::DataAllocator::OverflowAlloc(&pObject->TagMemAllocator, 0x10ui64);
  }
  else
  {
    pCurrent = pObject->TagMemAllocator.pCurrent;
    pObject->TagMemAllocator.pCurrent = pCurrent + 16;
    pObject->TagMemAllocator.BytesLeft = BytesLeft - 16;
  }
  if ( !pCurrent )
    return 0i64;
  *(_QWORD *)pCurrent = &Scaleform::GFx::ExecuteTag::`vftable;
  *(_QWORD *)pCurrent = &Scaleform::GFx::SetBackgroundColorTag::`vftable;
  return (Scaleform::GFx::SetBackgroundColorTag *)pCurrent;
}

// File Line: 287
// RVA: 0x880A80
Scaleform::GFx::AS2::PlaceObject2EHa *__fastcall Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::AS2::PlaceObject2EHa>(
        Scaleform::GFx::LoadProcess *this,
        unsigned __int64 len)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // r8
  unsigned __int64 v3; // rdx
  unsigned __int64 BytesLeft; // r9
  _QWORD *pCurrent; // rcx

  pObject = this->pLoadData.pObject;
  v3 = (len + 22) & 0xFFFFFFFFFFFFFFF8ui64;
  BytesLeft = pObject->TagMemAllocator.BytesLeft;
  if ( v3 > BytesLeft )
  {
    pCurrent = Scaleform::GFx::DataAllocator::OverflowAlloc(&pObject->TagMemAllocator, v3);
  }
  else
  {
    pCurrent = pObject->TagMemAllocator.pCurrent;
    pObject->TagMemAllocator.pCurrent = (char *)pCurrent + v3;
    pObject->TagMemAllocator.BytesLeft = BytesLeft - v3;
  }
  if ( !pCurrent )
    return 0i64;
  *pCurrent = &Scaleform::GFx::ExecuteTag::`vftable;
  *pCurrent = &Scaleform::GFx::GFxPlaceObjectBase::`vftable;
  *pCurrent = &Scaleform::GFx::PlaceObject2Tag::`vftable;
  *pCurrent = &Scaleform::GFx::AS2::PlaceObject2EH::`vftable;
  *pCurrent = &Scaleform::GFx::AS2::PlaceObject2EHa::`vftable;
  return (Scaleform::GFx::AS2::PlaceObject2EHa *)pCurrent;
}

// File Line: 291
// RVA: 0x8807C0
Scaleform::StringLH *__fastcall Scaleform::GFx::LoadProcess::AllocMovieDefClass<Scaleform::GFx::ImportData>(
        Scaleform::GFx::LoadProcess *this)
{
  Scaleform::GFx::DataAllocator *p_TagMemAllocator; // rcx
  unsigned __int64 BytesLeft; // rdx
  Scaleform::StringLH *pCurrent; // rbx

  p_TagMemAllocator = &this->pLoadData.pObject->TagMemAllocator;
  BytesLeft = p_TagMemAllocator->BytesLeft;
  if ( BytesLeft < 0x30 )
  {
    pCurrent = (Scaleform::StringLH *)Scaleform::GFx::DataAllocator::OverflowAlloc(p_TagMemAllocator, 0x30ui64);
  }
  else
  {
    pCurrent = (Scaleform::StringLH *)p_TagMemAllocator->pCurrent;
    p_TagMemAllocator->pCurrent += 48;
    p_TagMemAllocator->BytesLeft = BytesLeft - 48;
  }
  if ( !pCurrent )
    return 0i64;
  pCurrent->HeapTypeBits = 0i64;
  pCurrent[1].HeapTypeBits = 0i64;
  pCurrent[2].HeapTypeBits = 0i64;
  Scaleform::StringLH::StringLH(pCurrent + 3);
  pCurrent[4].HeapTypeBits = 0i64;
  pCurrent[5].HeapTypeBits = 0i64;
  return pCurrent;
}

// File Line: 298
// RVA: 0x8B1C70
Scaleform::GFx::ResourceHandle *__fastcall Scaleform::GFx::LoadProcess::AddNewResourceHandle(
        Scaleform::GFx::LoadProcess *this,
        Scaleform::GFx::ResourceHandle *result,
        unsigned int *rid)
{
  Scaleform::GFx::ResourceId rida; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::GFx::ResourceHandle *v6; // [rsp+48h] [rbp+10h]

  v6 = result;
  rida.Id = *rid;
  Scaleform::GFx::MovieDataDef::LoadTaskData::AddNewResourceHandle(
    this->pLoadData.pObject,
    result,
    (Scaleform::GFx::ResourceId)&rida);
  return result;
}

// File Line: 462
// RVA: 0x8B0E30
void __fastcall Scaleform::GFx::LoadProcess::AddExecuteTag(
        Scaleform::GFx::LoadProcess *this,
        Scaleform::GFx::ExecuteTag *ptag)
{
  Scaleform::ArrayDataBase<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0> > *v3; // rbx
  unsigned __int64 v4; // rdi
  unsigned __int64 v5; // r8
  Scaleform::GFx::ExecuteTag **Data; // rcx
  Scaleform::GFx::ExecuteTag **v7; // rcx

  v3 = (Scaleform::ArrayData<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0> > *)((char *)&this->FrameTags[0].Data + 16 * this->LoadState + 8 * this->LoadState);
  v4 = v3->Size + 1;
  if ( v4 >= v3->Size )
  {
    if ( v4 <= v3->Policy.Capacity )
      goto LABEL_7;
    v5 = v4 + (v4 >> 2);
  }
  else
  {
    if ( v4 >= v3->Policy.Capacity >> 1 )
      goto LABEL_7;
    v5 = v3->Size + 1;
  }
  Scaleform::ArrayDataBase<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0>>::Reserve(
    v3,
    v3,
    v5);
LABEL_7:
  Data = v3->Data;
  v3->Size = v4;
  v7 = &Data[v4 - 1];
  if ( v7 )
    *v7 = ptag;
}

// File Line: 468
// RVA: 0x8B1910
void __fastcall Scaleform::GFx::LoadProcess::AddInitAction(
        Scaleform::GFx::LoadProcess *this,
        Scaleform::GFx::ResourceId spriteId,
        Scaleform::GFx::ExecuteTag *ptag)
{
  Scaleform::Array<Scaleform::GFx::ExecuteTag *,2,Scaleform::ArrayConstPolicy<32,16,0> > *p_InitActionTags; // rbx
  unsigned __int64 Size; // rax
  unsigned __int64 v6; // rdi
  unsigned __int64 v7; // r8
  Scaleform::GFx::ExecuteTag **Data; // rcx
  Scaleform::GFx::ExecuteTag **v9; // rcx

  p_InitActionTags = &this->InitActionTags;
  Size = this->InitActionTags.Data.Size;
  v6 = Size + 1;
  if ( Size + 1 >= Size )
  {
    if ( v6 <= this->InitActionTags.Data.Policy.Capacity )
      goto LABEL_7;
    v7 = v6 + (v6 >> 2);
  }
  else
  {
    if ( v6 >= this->InitActionTags.Data.Policy.Capacity >> 1 )
      goto LABEL_7;
    v7 = Size + 1;
  }
  Scaleform::ArrayDataBase<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0>>::Reserve(
    &this->InitActionTags.Data,
    &this->InitActionTags,
    v7);
LABEL_7:
  Data = p_InitActionTags->Data.Data;
  p_InitActionTags->Data.Size = v6;
  v9 = &Data[v6 - 1];
  if ( v9 )
    *v9 = ptag;
}

// File Line: 506
// RVA: 0x8C98D0
void __fastcall Scaleform::GFx::LoadProcess::Execute(Scaleform::GFx::LoadProcess *this)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData::Read(this->pLoadData.pObject, this, this->pBindProcess.pObject);
}

// File Line: 518
// RVA: 0x8EC1E0
void __fastcall Scaleform::GFx::LoadProcess::OnAbandon(Scaleform::GFx::LoadProcess *this, bool started)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // rax
  Scaleform::GFx::MovieBindProcess *v3; // rcx
  Scaleform::GFx::MovieDefImpl::BindTaskData *v4; // rcx

  if ( started )
  {
    pObject = this->pLoadData.pObject;
    if ( pObject->LoadState <= LS_LoadingFrames )
      pObject->LoadingCanceled = 1;
  }
  v3 = this->pBindProcess.pObject;
  if ( v3 && !started )
  {
    v4 = v3->pBindData.pObject;
    if ( v4 )
      Scaleform::GFx::MovieDefImpl::BindTaskData::SetBindState(v4, 3u);
  }
}

