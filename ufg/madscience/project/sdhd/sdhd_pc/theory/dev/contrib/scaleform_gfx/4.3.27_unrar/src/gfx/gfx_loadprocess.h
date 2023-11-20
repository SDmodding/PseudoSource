// File Line: 172
// RVA: 0x906650
void __fastcall Scaleform::GFx::LoadProcess::SetBindProcess(Scaleform::GFx::LoadProcess *this, Scaleform::GFx::MovieBindProcess *pbindProcess)
{
  Scaleform::GFx::MovieBindProcess *v2; // rbx
  Scaleform::GFx::LoadProcess *v3; // rdi
  Scaleform::Render::RenderBuffer *v4; // rcx

  v2 = pbindProcess;
  v3 = this;
  if ( pbindProcess )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pbindProcess);
  v4 = (Scaleform::Render::RenderBuffer *)v3->pBindProcess.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  v3->pBindProcess.pObject = v2;
}

// File Line: 201
// RVA: 0x8DE5F0
Scaleform::GFx::SWFProcessInfo *__fastcall Scaleform::GFx::LoadProcess::GetStream(Scaleform::GFx::LoadProcess *this)
{
  Scaleform::GFx::SWFProcessInfo *result; // rax

  result = (Scaleform::GFx::SWFProcessInfo *)this->pAltStream;
  if ( !result )
    result = &this->ProcessInfo;
  return result;
}

// File Line: 209
// RVA: 0x8FDBE0
__int64 __fastcall Scaleform::GFx::LoadProcess::ReadU8(Scaleform::GFx::LoadProcess *this)
{
  Scaleform::GFx::Stream *v1; // rbx
  unsigned int v2; // eax
  __int64 v3; // rcx
  __int64 result; // rax

  v1 = this->pAltStream;
  if ( !v1 )
    v1 = &this->ProcessInfo.Stream;
  v2 = v1->DataSize;
  v1->UnusedBits = 0;
  if ( (signed int)(v2 - v1->Pos) < 1 )
    Scaleform::GFx::Stream::PopulateBuffer(v1, 1);
  v3 = v1->Pos;
  result = (unsigned __int8)v1->pBuffer[v3];
  v1->Pos = v3 + 1;
  return result;
}

// File Line: 210
// RVA: 0x8FDB00
unsigned __int16 __fastcall Scaleform::GFx::LoadProcess::ReadU16(Scaleform::GFx::LoadProcess *this)
{
  Scaleform::GFx::Stream *v1; // rbx
  unsigned int v2; // eax
  __int64 v3; // r8
  unsigned __int16 result; // ax

  v1 = this->pAltStream;
  if ( !v1 )
    v1 = &this->ProcessInfo.Stream;
  v2 = v1->DataSize;
  v1->UnusedBits = 0;
  if ( (signed int)(v2 - v1->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v1, 2);
  v3 = v1->Pos;
  result = (unsigned __int8)v1->pBuffer[v3] | (unsigned __int16)((unsigned __int8)v1->pBuffer[(unsigned int)(v3 + 1)] << 8);
  v1->Pos = v3 + 2;
  return result;
}

// File Line: 211
// RVA: 0x8FDB60
__int64 __fastcall Scaleform::GFx::LoadProcess::ReadU32(Scaleform::GFx::LoadProcess *this)
{
  Scaleform::GFx::Stream *v1; // rbx
  unsigned int v2; // eax
  __int64 v3; // r10
  char *v4; // r8
  __int64 result; // rax

  v1 = this->pAltStream;
  if ( !v1 )
    v1 = &this->ProcessInfo.Stream;
  v2 = v1->DataSize;
  v1->UnusedBits = 0;
  if ( (signed int)(v2 - v1->Pos) < 4 )
    Scaleform::GFx::Stream::PopulateBuffer(v1, 4);
  v3 = v1->Pos;
  v4 = v1->pBuffer;
  result = (unsigned __int8)v4[v3] | (((unsigned __int8)v4[(unsigned int)(v3 + 1)] | ((((unsigned __int8)v4[(unsigned int)(v3 + 3)] << 8) | (unsigned int)(unsigned __int8)v4[(unsigned int)(v3 + 2)]) << 8)) << 8);
  v1->Pos = v3 + 4;
  return result;
}

// File Line: 218
// RVA: 0x8E1190
Scaleform::File *__fastcall Scaleform::GFx::LoadProcess::GetUnderlyingFile(Scaleform::GFx::LoadProcess *this)
{
  Scaleform::GFx::Stream *v1; // rbx
  unsigned int v2; // eax

  v1 = this->pAltStream;
  if ( !v1 )
    v1 = &this->ProcessInfo.Stream;
  v2 = ((__int64 (__fastcall *)(Scaleform::File *, _QWORD, _QWORD))v1->pInput.pObject->vfptr[14].__vecDelDtor)(
         v1->pInput.pObject,
         v1->FilePos + v1->Pos - v1->DataSize,
         0i64);
  v1->ResyncFile = 1;
  if ( v2 != -1 )
  {
    v1->FilePos = v2;
    *(_QWORD *)&v1->Pos = 0i64;
  }
  return v1->pInput.pObject;
}

// File Line: 219
// RVA: 0x8DE7D0
__int64 __fastcall Scaleform::GFx::LoadProcess::GetTagEndPosition(Scaleform::GFx::LoadProcess *this)
{
  Scaleform::GFx::Stream *v1; // rdx
  __int64 v2; // rax
  __int64 result; // rax

  v1 = this->pAltStream;
  if ( !v1 )
    v1 = &this->ProcessInfo.Stream;
  v2 = v1->TagStackEntryCount - 1;
  if ( (unsigned int)v2 >= 2 )
    result = 0i64;
  else
    result = (unsigned int)v1->TagStack[v2];
  return result;
}

// File Line: 220
// RVA: 0x912CD0
__int64 __fastcall Scaleform::GFx::LoadProcess::Tell(Scaleform::GFx::LoadProcess *this)
{
  Scaleform::GFx::Stream *v1; // rdx

  v1 = this->pAltStream;
  if ( !v1 )
    v1 = &this->ProcessInfo.Stream;
  return v1->Pos + v1->FilePos - v1->DataSize;
}

// File Line: 284
// RVA: 0x880FE0
Scaleform::GFx::SetBackgroundColorTag *__fastcall Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::SetBackgroundColorTag>(Scaleform::GFx::LoadProcess *this)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *v1; // r8
  unsigned __int64 v2; // rdx
  char *v3; // rcx

  v1 = this->pLoadData.pObject;
  v2 = v1->TagMemAllocator.BytesLeft;
  if ( v2 < 0x10 )
  {
    v3 = (char *)Scaleform::GFx::DataAllocator::OverflowAlloc(&v1->TagMemAllocator, 0x10ui64);
  }
  else
  {
    v3 = v1->TagMemAllocator.pCurrent;
    v1->TagMemAllocator.pCurrent = v3 + 16;
    v1->TagMemAllocator.BytesLeft = v2 - 16;
  }
  if ( !v3 )
    return 0i64;
  *(_QWORD *)v3 = &Scaleform::GFx::ExecuteTag::`vftable;
  *(_QWORD *)v3 = &Scaleform::GFx::SetBackgroundColorTag::`vftable;
  return (Scaleform::GFx::SetBackgroundColorTag *)v3;
}

// File Line: 287
// RVA: 0x880A80
Scaleform::GFx::AS2::PlaceObject2EHa *__fastcall Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::AS2::PlaceObject2EHa>(Scaleform::GFx::LoadProcess *this, unsigned __int64 len)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *v2; // r8
  unsigned __int64 v3; // rdx
  unsigned __int64 v4; // r9
  _QWORD *v5; // rcx

  v2 = this->pLoadData.pObject;
  v3 = (len + 22) & 0xFFFFFFFFFFFFFFF8ui64;
  v4 = v2->TagMemAllocator.BytesLeft;
  if ( v3 > v4 )
  {
    v5 = Scaleform::GFx::DataAllocator::OverflowAlloc(&v2->TagMemAllocator, v3);
  }
  else
  {
    v5 = v2->TagMemAllocator.pCurrent;
    v2->TagMemAllocator.pCurrent = (char *)v5 + v3;
    v2->TagMemAllocator.BytesLeft = v4 - v3;
  }
  if ( !v5 )
    return 0i64;
  *v5 = &Scaleform::GFx::ExecuteTag::`vftable;
  *v5 = &Scaleform::GFx::GFxPlaceObjectBase::`vftable;
  *v5 = &Scaleform::GFx::PlaceObject2Tag::`vftable;
  *v5 = &Scaleform::GFx::AS2::PlaceObject2EH::`vftable;
  *v5 = &Scaleform::GFx::AS2::PlaceObject2EHa::`vftable;
  return (Scaleform::GFx::AS2::PlaceObject2EHa *)v5;
}

// File Line: 291
// RVA: 0x8807C0
Scaleform::StringLH *__fastcall Scaleform::GFx::LoadProcess::AllocMovieDefClass<Scaleform::GFx::ImportData>(Scaleform::GFx::LoadProcess *this)
{
  Scaleform::GFx::DataAllocator *v1; // rcx
  unsigned __int64 v2; // rdx
  Scaleform::StringLH *v3; // rbx
  Scaleform::String::DataDesc *v4; // rt1
  Scaleform::String::DataDesc *v5; // rcx

  v1 = &this->pLoadData.pObject->TagMemAllocator;
  v2 = v1->BytesLeft;
  if ( v2 < 0x30 )
  {
    v3 = (Scaleform::StringLH *)Scaleform::GFx::DataAllocator::OverflowAlloc(v1, 0x30ui64);
  }
  else
  {
    v3 = (Scaleform::StringLH *)v1->pCurrent;
    v1->pCurrent += 48;
    v1->BytesLeft = v2 - 48;
  }
  if ( !v3 )
    return 0i64;
  v3->HeapTypeBits = 0i64;
  v3[1].HeapTypeBits = 0i64;
  v3[2].HeapTypeBits = 0i64;
  Scaleform::StringLH::StringLH(v3 + 3);
  v3[4].HeapTypeBits = 0i64;
  v4 = v3[5].pData;
  v3[5].HeapTypeBits = 0i64;
  v5 = v3[5].pData;
  return v3;
}

// File Line: 298
// RVA: 0x8B1C70
Scaleform::GFx::ResourceHandle *__fastcall Scaleform::GFx::LoadProcess::AddNewResourceHandle(Scaleform::GFx::LoadProcess *this, Scaleform::GFx::ResourceHandle *result, __int64 rid)
{
  Scaleform::GFx::ResourceHandle *v3; // rbx
  Scaleform::GFx::ResourceId rida; // [rsp+40h] [rbp+8h]
  Scaleform::GFx::ResourceHandle *v6; // [rsp+48h] [rbp+10h]

  v6 = result;
  v3 = result;
  rida.Id = *(_DWORD *)rid;
  Scaleform::GFx::MovieDataDef::LoadTaskData::AddNewResourceHandle(
    this->pLoadData.pObject,
    result,
    (Scaleform::GFx::ResourceId)&rida);
  return v3;
}

// File Line: 462
// RVA: 0x8B0E30
void __fastcall Scaleform::GFx::LoadProcess::AddExecuteTag(Scaleform::GFx::LoadProcess *this, Scaleform::GFx::ExecuteTag *ptag)
{
  Scaleform::GFx::ExecuteTag *v2; // rsi
  Scaleform::ArrayDataBase<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0> > *v3; // rbx
  unsigned __int64 v4; // rdi
  unsigned __int64 v5; // r8
  Scaleform::GFx::ExecuteTag **v6; // rcx
  Scaleform::GFx::ExecuteTag **v7; // rcx

  v2 = ptag;
  v3 = (Scaleform::ArrayDataBase<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0> > *)&(&this->vfptr)[(signed int)this->LoadState + 2i64 * (signed int)this->LoadState + 121];
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
  v6 = v3->Data;
  v3->Size = v4;
  v7 = &v6[v4 - 1];
  if ( v7 )
    *v7 = v2;
}

// File Line: 468
// RVA: 0x8B1910
void __fastcall Scaleform::GFx::LoadProcess::AddInitAction(Scaleform::GFx::LoadProcess *this, Scaleform::GFx::ResourceId spriteId, Scaleform::GFx::ExecuteTag *ptag)
{
  Scaleform::Array<Scaleform::GFx::ExecuteTag *,2,Scaleform::ArrayConstPolicy<32,16,0> > *v3; // rbx
  Scaleform::GFx::ExecuteTag *v4; // rsi
  unsigned __int64 v5; // rax
  unsigned __int64 v6; // rdi
  unsigned __int64 v7; // r8
  Scaleform::GFx::ExecuteTag **v8; // rcx
  Scaleform::GFx::ExecuteTag **v9; // rcx

  v3 = &this->InitActionTags;
  v4 = ptag;
  v5 = this->InitActionTags.Data.Size;
  v6 = v5 + 1;
  if ( v5 + 1 >= v5 )
  {
    if ( v6 <= this->InitActionTags.Data.Policy.Capacity )
      goto LABEL_7;
    v7 = v6 + (v6 >> 2);
  }
  else
  {
    if ( v6 >= this->InitActionTags.Data.Policy.Capacity >> 1 )
      goto LABEL_7;
    v7 = v5 + 1;
  }
  Scaleform::ArrayDataBase<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0>>::Reserve(
    (Scaleform::ArrayDataBase<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0> > *)&this->InitActionTags.Data.Data,
    &this->InitActionTags,
    v7);
LABEL_7:
  v8 = v3->Data.Data;
  v3->Data.Size = v6;
  v9 = &v8[v6 - 1];
  if ( v9 )
    *v9 = v4;
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
  Scaleform::GFx::MovieDataDef::LoadTaskData *v2; // rax
  Scaleform::GFx::MovieBindProcess *v3; // rcx
  Scaleform::GFx::MovieDefImpl::BindTaskData *v4; // rcx

  if ( started )
  {
    v2 = this->pLoadData.pObject;
    if ( v2->LoadState <= 1 )
      v2->LoadingCanceled = 1;
  }
  v3 = this->pBindProcess.pObject;
  if ( v3 && !started )
  {
    v4 = v3->pBindData.pObject;
    if ( v4 )
      Scaleform::GFx::MovieDefImpl::BindTaskData::SetBindState(v4, 3u);
  }
}

