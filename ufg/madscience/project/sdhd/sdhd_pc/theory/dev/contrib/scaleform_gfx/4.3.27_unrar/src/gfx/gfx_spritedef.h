// File Line: 103
// RVA: 0x8D9140
float __fastcall Scaleform::GFx::SpriteDef::GetFrameRate(Scaleform::GFx::SpriteDef *this)
{
  return this->pMovieDef->pData.pObject->Header.FPS;
}

// File Line: 104
// RVA: 0x8D91A0
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::SpriteDef::GetFrameRect(Scaleform::GFx::SpriteDef *this, Scaleform::Render::Rect<float> *result)
{
  result->x2 = 1.0;
  result->y2 = 1.0;
  *(_QWORD *)&result->x1 = 0i64;
  return result;
}

// File Line: 106
// RVA: 0x8E1570
__int64 __fastcall Scaleform::GFx::SpriteDef::GetVersion(Scaleform::GFx::SpriteDef *this)
{
  return ((__int64 (*)(void))this->pMovieDef->vfptr[2].GetKey)();
}

// File Line: 107
// RVA: 0x8DDE60
__int64 __fastcall Scaleform::GFx::SpriteDef::GetSWFFlags(Scaleform::GFx::SpriteDef *this)
{
  return ((__int64 (*)(void))this->pMovieDef->vfptr[4].GetKey)();
}

// File Line: 109
// RVA: 0x8D7A80
__int64 __fastcall Scaleform::GFx::SpriteDef::GetFileBytes(Scaleform::GFx::SpriteDef *this)
{
  return this->pMovieDef->pData.pObject->Header.FileLength;
}

// File Line: 110
// RVA: 0x8D7BD0
const char *__fastcall Scaleform::GFx::SpriteDef::GetFileURL(Scaleform::GFx::SpriteDef *this)
{
  return (const char *)((this->pMovieDef->pData.pObject->FileURL.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
}

// File Line: 115
// RVA: 0x8DAA90
bool __fastcall Scaleform::GFx::SpriteDef::GetLabeledFrame(Scaleform::GFx::SpriteDef *this, const char *label, unsigned int *frameNumber, bool translateNumbers)
{
  return Scaleform::GFx::MovieDataDef::TranslateFrameString(&this->NamedFrames, label, frameNumber, translateNumbers);
}

// File Line: 119
// RVA: 0x8D8DF0
Scaleform::String *__fastcall Scaleform::GFx::SpriteDef::GetFrameLabel(Scaleform::GFx::SpriteDef *this, unsigned int frameNumber, unsigned int *exactFrameNumberForLabel)
{
  return Scaleform::GFx::MovieDataDef::TranslateNumberToFrameString(
           &this->NamedFrames,
           frameNumber,
           exactFrameNumberForLabel);
}

// File Line: 130
// RVA: 0x908AE0
void __fastcall Scaleform::GFx::SpriteDef::SetLoadingPlaylistFrame(Scaleform::GFx::SpriteDef *this, Scaleform::GFx::TimelineDef::Frame *frame, Scaleform::GFx::LogState *plog, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v6; // rax
  Scaleform::GFx::LogState *v7; // rbx
  Scaleform::GFx::SpriteDef *v8; // rdi
  Scaleform::Log *v9; // rax
  unsigned __int64 v10; // rsi

  v6 = this->LoadingFrame;
  v7 = plog;
  v8 = this;
  if ( SLODWORD(this->Playlist.Data.Size) > (signed int)v6 )
  {
    this->Playlist.Data.Data[v6] = *frame;
  }
  else if ( plog && (plog->pLog.pObject || Scaleform::Log::GetGlobalLog()) )
  {
    v9 = v7->pLog.pObject;
    v10 = v8->Playlist.Data.Size;
    if ( !v9 )
      v9 = Scaleform::Log::GetGlobalLog();
    Scaleform::Log::LogError(
      v9,
      "Invalid SWF file: failed to load sprite's frame #%d since total frames counter is %d",
      (unsigned int)(v8->LoadingFrame + 1),
      (unsigned int)v10,
      a5,
      a6);
  }
}

// File Line: 146
// RVA: 0x8DC210
Scaleform::GFx::TimelineDef::Frame *__fastcall Scaleform::GFx::SpriteDef::GetPlaylist(Scaleform::GFx::SpriteDef *this, Scaleform::GFx::TimelineDef::Frame *result, int frameNumber)
{
  Scaleform::GFx::TimelineDef::Frame *v3; // r9

  v3 = &this->Playlist.Data.Data[frameNumber];
  result->pTagPtrList = v3->pTagPtrList;
  result->TagCount = v3->TagCount;
  return result;
}

// File Line: 165
// RVA: 0x8DDD10
signed __int64 __fastcall Scaleform::GFx::SpriteDef::GetResourceTypeCode(Scaleform::GFx::SpriteDef *this)
{
  return 33792i64;
}

// File Line: 168
// RVA: 0x90B6F0
void __fastcall Scaleform::GFx::SpriteDef::SetScale9Grid(Scaleform::GFx::SpriteDef *this, Scaleform::Render::Rect<float> *r)
{
  Scaleform::Render::Rect<float> *v2; // rdi
  Scaleform::GFx::SpriteDef *v3; // rbx
  Scaleform::GFx::Scale9Grid *v4; // rax
  float *v5; // rcx
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  int v9; // [rsp+48h] [rbp+10h]
  Scaleform::GFx::Scale9Grid *v10; // [rsp+50h] [rbp+18h]

  v2 = r;
  v3 = this;
  if ( !this->pScale9Grid )
  {
    v9 = 258;
    v4 = (Scaleform::GFx::Scale9Grid *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::SpriteDef *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                         Scaleform::Memory::pGlobalHeap,
                                         this,
                                         16i64,
                                         &v9,
                                         -2i64);
    v10 = v4;
    if ( v4 )
    {
      *(_QWORD *)&v4->Rect.x1 = 0i64;
      *(_QWORD *)&v4->Rect.x2 = 0i64;
    }
    else
    {
      v4 = 0i64;
    }
    v3->pScale9Grid = v4;
  }
  v5 = &v3->pScale9Grid->Rect.x1;
  v6 = v2->y2;
  v7 = v2->x2;
  v8 = v2->y1;
  *v5 = v2->x1;
  v5[1] = v8;
  v5[2] = v7;
  v5[3] = v6;
}

// File Line: 307
// RVA: 0x8A8660
void __fastcall Scaleform::GFx::TimelineSnapshot::~TimelineSnapshot(Scaleform::GFx::TimelineSnapshot *this)
{
  Scaleform::GFx::TimelineSnapshot *v1; // rbx
  Scaleform::List<Scaleform::GFx::TimelineSnapshot::SnapshotElement,Scaleform::GFx::TimelineSnapshot::SnapshotElement> *v2; // r8
  Scaleform::GFx::TimelineSnapshot *v3; // rdx
  Scaleform::ListAllocBase<Scaleform::GFx::TimelineSnapshot::SnapshotElement,50,Scaleform::AllocatorDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement,2> >::PageType *v4; // rcx
  Scaleform::ListAllocBase<Scaleform::GFx::TimelineSnapshot::SnapshotElement,50,Scaleform::AllocatorDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement,2> >::PageType *v5; // rdx
  Scaleform::ListAllocBase<Scaleform::GFx::TimelineSnapshot::SnapshotElement,50,Scaleform::AllocatorDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement,2> >::PageType *v6; // rbx

  v1 = this;
  v2 = &this->SnapshotList;
  v3 = (Scaleform::GFx::TimelineSnapshot *)this->SnapshotList.Root.pNext;
  if ( v3 != (Scaleform::GFx::TimelineSnapshot *)&this->SnapshotList )
  {
    do
    {
      v4 = v3->SnapshotHeap.LastPage;
      v3->SnapshotHeap.FirstPage = (Scaleform::ListAllocBase<Scaleform::GFx::TimelineSnapshot::SnapshotElement,50,Scaleform::AllocatorDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement,2> >::PageType *)v1->SnapshotHeap.FirstEmptySlot;
      v1->SnapshotHeap.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::GFx::TimelineSnapshot::SnapshotElement,50,Scaleform::AllocatorDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement,2> >::NodeType *)v3;
      v3 = (Scaleform::GFx::TimelineSnapshot *)v4;
    }
    while ( v4 != (Scaleform::ListAllocBase<Scaleform::GFx::TimelineSnapshot::SnapshotElement,50,Scaleform::AllocatorDH<Scaleform::GFx::TimelineSnapshot::SnapshotElement,2> >::PageType *)v2 );
  }
  v2->Root.pPrev = (Scaleform::GFx::TimelineSnapshot::SnapshotElement *)v2;
  v2->Root.pNext = (Scaleform::GFx::TimelineSnapshot::SnapshotElement *)v2;
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->SnapshotSortedArray.Data.Data);
  v5 = v1->SnapshotHeap.FirstPage;
  if ( v1->SnapshotHeap.FirstPage )
  {
    do
    {
      v6 = v5->pNext;
      ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v5 = v6;
    }
    while ( v6 );
  }
}

