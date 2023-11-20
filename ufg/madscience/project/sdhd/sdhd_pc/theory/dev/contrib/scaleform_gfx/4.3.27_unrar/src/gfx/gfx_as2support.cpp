// File Line: 37
// RVA: 0x8C0EA0
Scaleform::GFx::MovieImpl *__fastcall Scaleform::GFx::AS2Support::CreateMovie(Scaleform::GFx::AS2Support *this, Scaleform::GFx::MemoryContext *memContext)
{
  Scaleform::GFx::AS2::MemoryContextImpl *v2; // rbp
  Scaleform::GFx::AS2Support *v3; // r14
  Scaleform::RefCountImplCoreVtbl *v4; // rsi
  Scaleform::GFx::MovieImpl *v5; // rax
  Scaleform::Render::RenderBuffer *v6; // rdi
  Scaleform::GFx::MovieImpl *v7; // rax
  Scaleform::GFx::MovieImpl *v8; // rbx
  Scaleform::GFx::AS2::MovieRoot *v9; // rax
  Scaleform::Render::RenderBuffer *v10; // rax

  v2 = (Scaleform::GFx::AS2::MemoryContextImpl *)memContext;
  v3 = this;
  v4 = memContext[1].vfptr;
  v5 = (Scaleform::GFx::MovieImpl *)(*((__int64 (__fastcall **)(Scaleform::RefCountImplCoreVtbl *, signed __int64, _QWORD))v4->__vecDelDtor
                                     + 10))(
                                      v4,
                                      21648i64,
                                      0i64);
  v6 = 0i64;
  if ( v5 )
  {
    Scaleform::GFx::MovieImpl::MovieImpl(v5, (Scaleform::MemoryHeap *)v4);
    v8 = v7;
  }
  else
  {
    v8 = 0i64;
  }
  v9 = (Scaleform::GFx::AS2::MovieRoot *)(*((__int64 (__fastcall **)(Scaleform::RefCountImplCoreVtbl *, signed __int64, _QWORD))v4->__vecDelDtor
                                          + 10))(
                                           v4,
                                           1600i64,
                                           0i64);
  if ( v9 )
  {
    Scaleform::GFx::AS2::MovieRoot::MovieRoot(v9, v2, v8, (Scaleform::GFx::ASSupport *)&v3->vfptr);
    v6 = v10;
  }
  v8->Flags2 |= 1u;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  return v8;
}

// File Line: 48
// RVA: 0x8BE610
Scaleform::Ptr<Scaleform::GFx::ASIMEManager> *__fastcall Scaleform::GFx::AS3Support::CreateASIMEManager(Scaleform::GFx::AS3Support *this, Scaleform::Ptr<Scaleform::GFx::ASIMEManager> *result)
{
  result->pObject = 0i64;
  return result;
}

// File Line: 60
// RVA: 0x8C0AD0
Scaleform::GFx::MemoryContext *__fastcall Scaleform::GFx::AS2Support::CreateMemoryContext(Scaleform::GFx::AS2Support *this, const char *heapName, Scaleform::GFx::MemoryParams *memParams, bool debugHeap)
{
  Scaleform::GFx::MemoryParams *v4; // rbp
  signed __int64 v5; // rax
  Scaleform::MemoryHeap *v6; // rdi
  Scaleform::GFx::AS2::MemoryContextImpl *v7; // rax
  __int64 v8; // rsi
  __int64 v9; // rax
  __int64 v10; // rbx
  Scaleform::GFx::AS2::ASRefCountCollector *v11; // rax
  Scaleform::GFx::AS2::ASRefCountCollector *v12; // rax
  Scaleform::GFx::AS2::ASRefCountCollector *v13; // r14
  Scaleform::Render::RenderBuffer *v14; // rcx
  Scaleform::GFx::ASStringManager *v15; // rax
  __int64 v16; // rax
  Scaleform::Render::RenderBuffer *v17; // rcx
  __m128i v19; // [rsp+30h] [rbp-58h]
  __int128 v20; // [rsp+40h] [rbp-48h]
  __int128 v21; // [rsp+50h] [rbp-38h]
  __int128 v22; // [rsp+60h] [rbp-28h]

  v4 = memParams;
  v19 = *(__m128i *)&memParams->Desc.Flags;
  v20 = *(_OWORD *)&memParams->Desc.Granularity;
  v21 = *(_OWORD *)&memParams->Desc.Threshold;
  v22 = *(_OWORD *)&memParams->Desc.HeapId;
  v19.m128i_i32[0] = (debugHeap != 0 ? 0x1000 : 0) | 3 | _mm_cvtsi128_si32(v19);
  *(_QWORD *)&v22 = 3i64;
  v5 = memParams->InitialDynamicLimit;
  if ( (_DWORD)v5 == -1 )
    v5 = 0x20000i64;
  *((_QWORD *)&v21 + 1) = v5;
  v6 = (Scaleform::MemoryHeap *)(*(__int64 (__fastcall **)(Scaleform::MemoryHeap *, const char *, __m128i *))&Scaleform::Memory::pGlobalHeap->vfptr->gap8[24])(
                                  Scaleform::Memory::pGlobalHeap,
                                  heapName,
                                  &v19);
  Scaleform::MemoryHeap::AssignToCurrentThread(v6);
  v7 = (Scaleform::GFx::AS2::MemoryContextImpl *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v6->vfptr->Alloc)(
                                                   v6,
                                                   104i64);
  v8 = 0i64;
  if ( v7 )
  {
    Scaleform::GFx::AS2::MemoryContextImpl::MemoryContextImpl(v7);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  *(_QWORD *)(v10 + 16) = v6;
  v11 = (Scaleform::GFx::AS2::ASRefCountCollector *)v6->vfptr->Alloc(v6, 152ui64, 0i64);
  if ( v11 )
  {
    Scaleform::GFx::AS2::ASRefCountCollector::ASRefCountCollector(v11);
    v13 = v12;
  }
  else
  {
    v13 = 0i64;
  }
  v14 = *(Scaleform::Render::RenderBuffer **)(v10 + 32);
  if ( v14 )
    Scaleform::RefCountImpl::Release(v14);
  *(_QWORD *)(v10 + 32) = v13;
  Scaleform::GFx::AS2::ASRefCountCollector::SetParams(v13, v4->FramesBetweenCollections, v4->MaxCollectionRoots);
  v15 = (Scaleform::GFx::ASStringManager *)v6->vfptr->Alloc(v6, 160ui64, 0i64);
  if ( v15 )
  {
    Scaleform::GFx::ASStringManager::ASStringManager(v15, v6);
    v8 = v16;
  }
  v17 = *(Scaleform::Render::RenderBuffer **)(v10 + 24);
  if ( v17 )
    Scaleform::RefCountImpl::Release(v17);
  *(_QWORD *)(v10 + 24) = v8;
  *(_QWORD *)(v10 + 72) = v4->Desc.Limit;
  *(float *)(v10 + 96) = v4->HeapLimitMultiplier;
  v6->vfptr->SetLimitHandler(v6, (Scaleform::MemoryHeap::LimitHandler *)(v10 + 48));
  Scaleform::MemoryHeap::ReleaseOnFree((ANTLR3_COMMON_TOKEN_struct *)v6, v10);
  return (Scaleform::GFx::MemoryContext *)v10;
}

// File Line: 100
// RVA: 0x8BEAB0
Scaleform::GFx::Button *__fastcall Scaleform::GFx::AS2Support::CreateCharacterInstance(Scaleform::GFx::AS2Support *this, Scaleform::GFx::MovieImpl *proot, Scaleform::GFx::CharacterCreateInfo *ccinfo, Scaleform::GFx::InteractiveObject *pparent, __int64 rid, Scaleform::GFx::CharacterDef::CharacterDefType type)
{
  Scaleform::GFx::InteractiveObject *parent; // r14
  Scaleform::GFx::CharacterCreateInfo *v7; // rsi
  Scaleform::GFx::MovieImpl *v8; // rbx
  Scaleform::GFx::CharacterDef::CharacterDefType v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  __int64 v15; // rdi
  Scaleform::GFx::Button *v16; // rax
  Scaleform::GFx::Button *v17; // rbx
  Scaleform::GFx::StaticTextCharacter *v18; // rax
  Scaleform::GFx::Button *v19; // rax
  __int64 v20; // rdi
  Scaleform::GFx::Button *v21; // rax
  __int64 v22; // rdi
  Scaleform::GFx::Button *v23; // rax
  Scaleform::GFx::AS2::GenericDisplayObj *v24; // rax
  Scaleform::GFx::Button *v25; // rax
  Scaleform::GFx::ResourceId v26; // [rsp+40h] [rbp-20h]
  __int64 v27; // [rsp+48h] [rbp-18h]
  __int64 v28; // [rsp+50h] [rbp-10h]
  __int64 v29; // [rsp+58h] [rbp-8h]

  v27 = -2i64;
  parent = pparent;
  v7 = ccinfo;
  v8 = proot;
  v9 = type;
  if ( type == Unknown )
    v9 = ((unsigned int (*)(void))ccinfo->pCharDef->vfptr[1].__vecDelDtor)();
  v10 = v9 - 1;
  if ( v10 )
  {
    v11 = v10 - 2;
    if ( v11 )
    {
      v12 = v11 - 1;
      if ( v12 )
      {
        v13 = v12 - 1;
        if ( v13 )
        {
          if ( v13 != 1 )
            return 0i64;
          v15 = (__int64)v8->pHeap->vfptr->Alloc(v8->pHeap, 424ui64, 0i64);
          v28 = v15;
          v29 = v15;
          if ( v15 )
          {
            type = *(_DWORD *)rid;
            Scaleform::GFx::Button::Button(
              (Scaleform::GFx::Button *)v15,
              (Scaleform::GFx::ButtonDef *)v7->pCharDef,
              v7->pBindDefImpl,
              v8->pASMovieRoot.pObject,
              parent,
              (Scaleform::GFx::ResourceId)&type);
            v17 = v16;
          }
          else
          {
            v17 = 0i64;
          }
          v29 = v15 + 368;
          if ( v15 != -368 )
            Scaleform::GFx::AS2::AvmButton::AvmButton((Scaleform::GFx::AS2::AvmButton *)(v15 + 368), v17);
        }
        else
        {
          v29 = (__int64)v8->pHeap;
          v18 = (Scaleform::GFx::StaticTextCharacter *)(*(__int64 (__fastcall **)(Scaleform::GFx::AS2Support *, signed __int64, _QWORD))(*(_QWORD *)v29 + 80i64))(
                                                         this,
                                                         400i64,
                                                         0i64);
          v28 = (__int64)v18;
          if ( v18 )
          {
            type = *(_DWORD *)rid;
            Scaleform::GFx::StaticTextCharacter::StaticTextCharacter(
              v18,
              (Scaleform::GFx::StaticTextDef *)v7->pCharDef,
              v7->pBindDefImpl,
              v8->pASMovieRoot.pObject);
            v17 = v19;
          }
          else
          {
            v17 = 0i64;
          }
        }
      }
      else
      {
        v20 = (__int64)v8->pHeap->vfptr->Alloc(v8->pHeap, 408ui64, 0i64);
        v29 = v20;
        v28 = v20;
        if ( v20 )
        {
          type = *(_DWORD *)rid;
          Scaleform::GFx::TextField::TextField(
            (Scaleform::GFx::TextField *)v20,
            (Scaleform::GFx::TextFieldDef *)v7->pCharDef,
            v7->pBindDefImpl,
            v8->pASMovieRoot.pObject,
            parent,
            (Scaleform::GFx::ResourceId)&type);
          v17 = v21;
        }
        else
        {
          v17 = 0i64;
        }
        v28 = v20 + 312;
        if ( v20 != -312 )
          Scaleform::GFx::AS2::AvmTextField::AvmTextField(
            (Scaleform::GFx::AS2::AvmTextField *)(v20 + 312),
            (Scaleform::GFx::TextField *)v17);
      }
    }
    else
    {
      v22 = (__int64)v8->pHeap->vfptr->Alloc(v8->pHeap, 824ui64, 0i64);
      v29 = v22;
      v28 = v22;
      if ( v22 )
      {
        type = *(_DWORD *)rid;
        Scaleform::GFx::Sprite::Sprite(
          (Scaleform::GFx::Sprite *)v22,
          (Scaleform::GFx::TimelineDef *)v7->pCharDef,
          v7->pBindDefImpl,
          v8->pASMovieRoot.pObject,
          parent,
          (Scaleform::GFx::ResourceId)&type,
          0);
        v17 = v23;
      }
      else
      {
        v17 = 0i64;
      }
      v28 = v22 + 320;
      if ( v22 != -320 )
        Scaleform::GFx::AS2::AvmSprite::AvmSprite(
          (Scaleform::GFx::AS2::AvmSprite *)(v22 + 320),
          (Scaleform::GFx::Sprite *)v17);
    }
  }
  else
  {
    type = 322;
    v24 = (Scaleform::GFx::AS2::GenericDisplayObj *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                      Scaleform::Memory::pGlobalHeap,
                                                      parent,
                                                      120ui64,
                                                      (Scaleform::AllocInfo *)&type);
    v29 = (__int64)v24;
    if ( v24 )
    {
      v26.Id = *(_DWORD *)rid;
      Scaleform::GFx::AS2::GenericDisplayObj::GenericDisplayObj(
        v24,
        v7->pCharDef,
        v8->pASMovieRoot.pObject,
        parent,
        (Scaleform::GFx::ResourceId)&v26);
      v17 = v25;
    }
    else
    {
      v17 = 0i64;
    }
  }
  return v17;
}

// File Line: 181
// RVA: 0x8A7130
void __fastcall Scaleform::GFx::AS2::PlaceObject2EH::~PlaceObject2EH(Scaleform::GFx::AS2::PlaceObject2EH *this)
{
  Scaleform::GFx::AS2::PlaceObject2EH *v1; // r14
  __int64 v2; // rsi
  unsigned __int64 v3; // rbx
  unsigned __int64 v4; // rbp
  _QWORD *v5; // rdi
  Scaleform::Render::RenderBuffer *v6; // rcx

  v1 = this;
  this->vfptr = (Scaleform::GFx::ExecuteTagVtbl *)&Scaleform::GFx::AS2::PlaceObject2EH::`vftable';
  if ( this->pData[0] < 0 )
  {
    v2 = *(_QWORD *)&this->pData[1];
    if ( v2 )
    {
      v3 = 0i64;
      v4 = *(_QWORD *)(v2 + 8);
      if ( v4 )
      {
        do
        {
          v5 = *(_QWORD **)(*(_QWORD *)v2 + 8 * v3);
          if ( v5 )
          {
            v6 = (Scaleform::Render::RenderBuffer *)v5[3];
            if ( v6 )
              Scaleform::RefCountImpl::Release(v6);
            Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v5);
          }
          ++v3;
        }
        while ( v3 < v4 );
      }
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, *(void **)v2);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, (void *)v2);
    }
  }
  v1->vfptr = (Scaleform::GFx::ExecuteTagVtbl *)&Scaleform::GFx::PlaceObject2Tag::`vftable';
  v1->vfptr = (Scaleform::GFx::ExecuteTagVtbl *)&Scaleform::GFx::ExecuteTag::`vftable';
}

// File Line: 198
// RVA: 0x915680
void __fastcall Scaleform::GFx::PlaceObject2Tag::Unpack(Scaleform::GFx::PlaceObject2Tag *this, Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *data)
{
  Scaleform::GFx::PlaceObject2Tag::UnpackBase(this, data, 6);
}

// File Line: 202
// RVA: 0x8C9F80
void __fastcall Scaleform::GFx::PlaceObject2Tag::Execute(Scaleform::GFx::PlaceObject2Tag *this, Scaleform::GFx::DisplayObjContainer *m)
{
  Scaleform::GFx::PlaceObject2Tag::ExecuteBase(this, m, 6);
}

// File Line: 212
// RVA: 0x915690
void __fastcall Scaleform::GFx::PlaceObject2Taga::Unpack(Scaleform::GFx::PlaceObject2Taga *this, Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *data)
{
  Scaleform::GFx::PlaceObject2Tag::UnpackBase((Scaleform::GFx::PlaceObject2Tag *)&this->vfptr, data, 3);
}

// File Line: 216
// RVA: 0x8C9F90
void __fastcall Scaleform::GFx::AS2::PlaceObject2EHa::Execute(Scaleform::GFx::PlaceObject2Taga *this, Scaleform::GFx::DisplayObjContainer *m)
{
  Scaleform::GFx::PlaceObject2Tag::ExecuteBase((Scaleform::GFx::PlaceObject2Tag *)&this->vfptr, m, 3);
}

// File Line: 221
// RVA: 0x8F0F90
void __fastcall Scaleform::GFx::AS2::PlaceObject2EHa::ProcessEventHandlers(Scaleform::GFx::AS2::PlaceObject2EHa *this, Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *data, Scaleform::GFx::StreamContext *sc, const char *prawdata)
{
  Scaleform::GFx::AS2::PlaceObject2EH::ProcessEventHandlers(
    (Scaleform::GFx::AS2::PlaceObject2EH *)&this->vfptr,
    data,
    sc,
    prawdata,
    3);
}

// File Line: 232
// RVA: 0x8A7240
void __fastcall Scaleform::GFx::AS2::PlaceObject3EH::~PlaceObject3EH(Scaleform::GFx::AS2::PlaceObject3EH *this)
{
  Scaleform::GFx::AS2::PlaceObject3EH *v1; // r14
  __int64 v2; // rsi
  unsigned __int64 v3; // rbx
  unsigned __int64 v4; // rbp
  _QWORD *v5; // rdi
  Scaleform::Render::RenderBuffer *v6; // rcx

  v1 = this;
  this->vfptr = (Scaleform::GFx::ExecuteTagVtbl *)&Scaleform::GFx::AS2::PlaceObject3EH::`vftable';
  if ( this->pData[0] < 0 )
  {
    v2 = *(_QWORD *)&this->pData[1];
    if ( v2 )
    {
      v3 = 0i64;
      v4 = *(_QWORD *)(v2 + 8);
      if ( v4 )
      {
        do
        {
          v5 = *(_QWORD **)(*(_QWORD *)v2 + 8 * v3);
          if ( v5 )
          {
            v6 = (Scaleform::Render::RenderBuffer *)v5[3];
            if ( v6 )
              Scaleform::RefCountImpl::Release(v6);
            Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v5);
          }
          ++v3;
        }
        while ( v3 < v4 );
      }
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, *(void **)v2);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, (void *)v2);
    }
  }
  v1->vfptr = (Scaleform::GFx::ExecuteTagVtbl *)&Scaleform::GFx::PlaceObject3Tag::`vftable';
  v1->vfptr = (Scaleform::GFx::ExecuteTagVtbl *)&Scaleform::GFx::ExecuteTag::`vftable';
}

// File Line: 254
// RVA: 0x8F0DA0
void __fastcall Scaleform::GFx::AS2::PlaceObject2EH::ProcessEventHandlers(Scaleform::GFx::AS2::PlaceObject2EH *this, Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *data, Scaleform::GFx::StreamContext *sc, const char *prawdata, char version)
{
  Scaleform::GFx::StreamContext *v5; // rdi
  Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *v6; // r15
  Scaleform::GFx::AS2::PlaceObject2EH *v7; // r13
  Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *v8; // rax
  unsigned __int64 v9; // rax
  unsigned __int64 v10; // rax
  Scaleform::ArrayDataBase<Scaleform::GFx::SwfEvent *,Scaleform::AllocatorLH<Scaleform::GFx::SwfEvent *,260>,Scaleform::ArrayDefaultPolicy> *v11; // rax
  Scaleform::ArrayDataBase<Scaleform::GFx::SwfEvent *,Scaleform::AllocatorLH<Scaleform::GFx::SwfEvent *,260>,Scaleform::ArrayDefaultPolicy> *v12; // rsi
  unsigned __int64 v13; // rdx
  int v14; // ebp
  signed __int64 v15; // rax
  __int64 v16; // rax
  Scaleform::GFx::AS2::AvmSwfEvent *v17; // rbx
  unsigned __int64 v18; // rax
  unsigned __int64 v19; // rbp
  unsigned __int64 v20; // r8
  Scaleform::GFx::AS2::AvmSwfEvent **v21; // rcx

  v5 = sc;
  v6 = data;
  v7 = this;
  v8 = *(Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> **)(prawdata + 1);
  if ( !v8 )
  {
    if ( sc->CurBitIndex )
      ++sc->CurByteIndex;
    sc->CurBitIndex = 0;
    sc->CurByteIndex += 2i64;
    v9 = sc->CurByteIndex;
    sc->CurBitIndex = 0;
    if ( (unsigned __int8)version < 6u )
      v10 = v9 + 2;
    else
      v10 = v9 + 4;
    sc->CurByteIndex = v10;
    v11 = (Scaleform::ArrayDataBase<Scaleform::GFx::SwfEvent *,Scaleform::AllocatorLH<Scaleform::GFx::SwfEvent *,260>,Scaleform::ArrayDefaultPolicy> *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(Scaleform::Memory::pGlobalHeap, 24i64);
    v12 = v11;
    if ( v11 )
    {
      v11->Data = 0i64;
      v11->Size = 0i64;
      v11->Policy.Capacity = 0i64;
    }
    else
    {
      v12 = 0i64;
    }
    while ( 1 )
    {
      if ( v5->CurBitIndex )
        ++v5->CurByteIndex;
      v5->CurBitIndex = 0;
      v5->CurBitIndex = 0;
      v13 = v5->CurByteIndex;
      if ( (unsigned __int8)version < 6u )
      {
        v15 = v13 + 2;
        v14 = *(unsigned __int16 *)&v5->pData[v13];
      }
      else
      {
        v14 = (unsigned __int8)v5->pData[v13] | (((unsigned __int8)v5->pData[v13 + 1] | (*(unsigned __int16 *)&v5->pData[v13 + 2] << 8)) << 8);
        v15 = v13 + 4;
      }
      v5->CurByteIndex = v15;
      if ( !v14 )
      {
        *(_QWORD *)&v7->pData[1] = v12;
        v6->pEventHandlers = (Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *)v12;
        return;
      }
      v16 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
              Scaleform::Memory::pGlobalHeap,
              32i64);
      v17 = (Scaleform::GFx::AS2::AvmSwfEvent *)v16;
      if ( v16 )
      {
        *(_QWORD *)v16 = 0i64;
        *(_DWORD *)(v16 + 8) = 0;
        *(_BYTE *)(v16 + 12) = 0;
        *(_DWORD *)(v16 + 16) = 65280;
        *(_QWORD *)(v16 + 24) = 0i64;
      }
      else
      {
        v17 = 0i64;
      }
      Scaleform::GFx::AS2::AvmSwfEvent::Read(v17, v5, v14);
      v18 = v12->Size;
      v19 = v18 + 1;
      if ( v18 + 1 >= v18 )
      {
        if ( v19 > v12->Policy.Capacity )
        {
          v20 = v19 + (v19 >> 2);
          goto LABEL_24;
        }
      }
      else if ( v19 < v12->Policy.Capacity >> 1 )
      {
        v20 = v18 + 1;
LABEL_24:
        Scaleform::ArrayDataBase<Scaleform::GFx::SwfEvent *,Scaleform::AllocatorLH<Scaleform::GFx::SwfEvent *,260>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v12,
          v12,
          v20);
        goto LABEL_25;
      }
LABEL_25:
      v12->Size = v19;
      v21 = (Scaleform::GFx::AS2::AvmSwfEvent **)&v12->Data[v19 - 1];
      if ( v21 )
        *v21 = v17;
    }
  }
  data->pEventHandlers = v8;
}vmSwfEvent **)&v12->Data[v19 

// File Line: 296
// RVA: 0x8F0FA0
void __fastcall Scaleform::GFx::AS2::PlaceObject3EH::ProcessEventHandlers(Scaleform::GFx::AS2::PlaceObject3EH *this, Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *data, Scaleform::GFx::StreamContext *sc, const char *__formal)
{
  Scaleform::GFx::StreamContext *v4; // r14
  Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *v5; // rbp
  Scaleform::GFx::AS2::PlaceObject3EH *v6; // r15
  Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *v7; // rax
  Scaleform::ArrayDataBase<Scaleform::GFx::SwfEvent *,Scaleform::AllocatorLH<Scaleform::GFx::SwfEvent *,260>,Scaleform::ArrayDefaultPolicy> *v8; // rax
  Scaleform::ArrayDataBase<Scaleform::GFx::SwfEvent *,Scaleform::AllocatorLH<Scaleform::GFx::SwfEvent *,260>,Scaleform::ArrayDefaultPolicy> *v9; // rdi
  unsigned __int64 v10; // rdx
  const char *v11; // rcx
  bool v12; // zf
  int v13; // esi
  __int64 v14; // rax
  Scaleform::GFx::AS2::AvmSwfEvent *v15; // rbx
  unsigned __int64 v16; // rax
  unsigned __int64 v17; // rsi
  unsigned __int64 v18; // r8
  Scaleform::GFx::AS2::AvmSwfEvent **v19; // rcx

  v4 = sc;
  v5 = data;
  v6 = this;
  v7 = *(Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> **)&this->pData[1];
  if ( !v7 )
  {
    if ( sc->CurBitIndex )
      ++sc->CurByteIndex;
    sc->CurBitIndex = 0;
    sc->CurByteIndex += 6i64;
    v8 = (Scaleform::ArrayDataBase<Scaleform::GFx::SwfEvent *,Scaleform::AllocatorLH<Scaleform::GFx::SwfEvent *,260>,Scaleform::ArrayDefaultPolicy> *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64, _QWORD, const char *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(Scaleform::Memory::pGlobalHeap, 24i64, 0i64, __formal, -2i64);
    v9 = v8;
    if ( v8 )
    {
      v8->Data = 0i64;
      v8->Size = 0i64;
      v8->Policy.Capacity = 0i64;
    }
    else
    {
      v9 = 0i64;
    }
    while ( 1 )
    {
      if ( v4->CurBitIndex )
        ++v4->CurByteIndex;
      v4->CurBitIndex = 0;
      v10 = v4->CurByteIndex;
      v11 = &v4->pData[v10];
      v12 = (*(unsigned __int8 *)v11 | ((*((unsigned __int8 *)v11 + 1) | (*((unsigned __int16 *)v11 + 1) << 8)) << 8)) == 0;
      v13 = *(unsigned __int8 *)v11 | ((*((unsigned __int8 *)v11 + 1) | (*((unsigned __int16 *)v11 + 1) << 8)) << 8);
      v4->CurByteIndex = v10 + 4;
      if ( v12 )
      {
        *(_QWORD *)&v6->pData[1] = v9;
        v5->pEventHandlers = (Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *)v9;
        return;
      }
      v14 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
              Scaleform::Memory::pGlobalHeap,
              32i64);
      v15 = (Scaleform::GFx::AS2::AvmSwfEvent *)v14;
      if ( v14 )
      {
        *(_QWORD *)v14 = 0i64;
        *(_DWORD *)(v14 + 8) = 0;
        *(_BYTE *)(v14 + 12) = 0;
        *(_DWORD *)(v14 + 16) = 65280;
        *(_QWORD *)(v14 + 24) = 0i64;
      }
      else
      {
        v15 = 0i64;
      }
      Scaleform::GFx::AS2::AvmSwfEvent::Read(v15, v4, v13);
      v16 = v9->Size;
      v17 = v16 + 1;
      if ( v16 + 1 >= v16 )
      {
        if ( v17 > v9->Policy.Capacity )
        {
          v18 = v17 + (v17 >> 2);
          goto LABEL_18;
        }
      }
      else if ( v17 < v9->Policy.Capacity >> 1 )
      {
        v18 = v16 + 1;
LABEL_18:
        Scaleform::ArrayDataBase<Scaleform::GFx::SwfEvent *,Scaleform::AllocatorLH<Scaleform::GFx::SwfEvent *,260>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v9,
          v9,
          v18);
        goto LABEL_19;
      }
LABEL_19:
      v9->Size = v17;
      v19 = (Scaleform::GFx::AS2::AvmSwfEvent **)&v9->Data[v17 - 1];
      if ( v19 )
        *v19 = v15;
    }
  }
  data->pEventHandlers = v7;
}

// File Line: 370
// RVA: 0x8BA980
void __fastcall Scaleform::GFx::AS2::RemoveObjectEH::CheckEventHandlers(Scaleform::GFx::AS2::RemoveObjectEH *this, void **pse, Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *pevts)
{
  unsigned __int64 v3; // r10
  _BYTE *v4; // r9
  unsigned __int64 v5; // rcx
  Scaleform::GFx::SwfEvent **v6; // r8

  v3 = pevts->Data.Size;
  v4 = *pse;
  v5 = 0i64;
  if ( v3 )
  {
    v6 = pevts->Data.Data;
    while ( !((*v6)->Event.Id & 4) )
    {
      ++v5;
      ++v6;
      if ( v5 >= v3 )
        goto LABEL_5;
    }
    v4[105] |= 2u;
    *pse = 0i64;
  }
  else
  {
LABEL_5:
    *pse = v4;
  }
}

// File Line: 389
// RVA: 0x8F58D0
void __fastcall Scaleform::GFx::AS2::ButtonAction::Read(Scaleform::GFx::AS2::ButtonAction *this, Scaleform::GFx::Stream *pin, Scaleform::GFx::TagType tagType, unsigned int actionLength)
{
  unsigned int v4; // esi
  Scaleform::GFx::Stream *v5; // rbx
  Scaleform::GFx::AS2::ButtonAction *v6; // rbp
  __int64 v7; // r9
  unsigned __int16 v8; // r8
  __int64 v9; // r8
  Scaleform::GFx::AS2::ActionBufferData *v10; // rdi
  Scaleform::Ptr<Scaleform::GFx::AS2::ActionBufferData> *v11; // rbx

  if ( actionLength )
  {
    v4 = actionLength;
    v5 = pin;
    v6 = this;
    if ( tagType == 7 )
    {
      this->Conditions = 8;
    }
    else
    {
      pin->UnusedBits = 0;
      if ( (signed int)(pin->DataSize - pin->Pos) < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(pin, 2);
      v7 = v5->Pos;
      v8 = (unsigned __int8)v5->pBuffer[v7] | (unsigned __int16)((unsigned __int8)v5->pBuffer[(unsigned int)(v7 + 1)] << 8);
      v5->Pos = v7 + 2;
      v6->Conditions = v8;
      v4 -= 2;
    }
    v9 = (unsigned int)v6->Conditions;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v5->vfptr,
      "-- action conditions %X\n");
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v5->vfptr,
      "-- actions in button\n");
    v10 = Scaleform::GFx::AS2::ActionBufferData::CreateNew();
    Scaleform::GFx::AS2::ActionBufferData::Read(v10, v5, v4);
    Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy> *)&v6->Actions,
      &v6->Actions,
      v6->Actions.Data.Size + 1);
    v11 = &v6->Actions.Data.Data[v6->Actions.Data.Size - 1];
    if ( v11 )
    {
      if ( v10 )
        Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v10);
      v11->pObject = v10;
    }
    if ( v10 )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v10);
  }
}

// File Line: 424
// RVA: 0x8F6680
void __fastcall Scaleform::GFx::AS2::DoActionTag::Read(Scaleform::GFx::AS2::DoActionTag *this, Scaleform::GFx::LoadProcess *p)
{
  Scaleform::GFx::Stream *v2; // rdi
  Scaleform::GFx::LoadProcess *v3; // rbx
  Scaleform::GFx::AS2::DoActionTag *v4; // rsi
  Scaleform::GFx::AS2::ActionBufferData *v5; // rax
  Scaleform::Render::RenderBuffer *v6; // rcx
  Scaleform::GFx::AS2::ActionBufferData *v7; // rbp
  Scaleform::GFx::SWFProcessInfo *v8; // rcx
  signed __int64 v9; // rdx
  __int64 v10; // rax
  int v11; // er9

  v2 = p->pAltStream;
  v3 = p;
  v4 = this;
  if ( !v2 )
    v2 = &p->ProcessInfo.Stream;
  v5 = Scaleform::GFx::AS2::ActionBufferData::CreateNew();
  v6 = (Scaleform::Render::RenderBuffer *)v4->pBuf.pObject;
  v7 = v5;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  v4->pBuf.pObject = v7;
  v8 = (Scaleform::GFx::SWFProcessInfo *)v3->pAltStream;
  v9 = (signed __int64)&v3->ProcessInfo;
  if ( v8 )
    v9 = (signed __int64)v3->pAltStream;
  v10 = (unsigned int)(*(_DWORD *)(v9 + 72) - 1);
  if ( (unsigned int)v10 >= 2 )
    v11 = 0;
  else
    v11 = *(_DWORD *)(v9 + 4 * v10 + 64);
  if ( !v8 )
    v8 = &v3->ProcessInfo;
  Scaleform::GFx::AS2::ActionBufferData::Read(v7, v2, v11 + v8->Stream.DataSize - v8->Stream.FilePos - v8->Stream.Pos);
}

// File Line: 448
// RVA: 0x8C9380
void __fastcall Scaleform::GFx::AS2::DoActionTag::Execute(Scaleform::GFx::AS2::DoActionTag *this, Scaleform::GFx::DisplayObjContainer *m)
{
  Scaleform::GFx::AS2::DoActionTag *v2; // rsi
  Scaleform::GFx::AS2::AvmSprite *v3; // rdi
  __int64 v4; // rax
  Scaleform::GFx::AS2::ActionBufferData *v5; // rcx
  char *v6; // rcx
  Scaleform::GFx::AS2::ASStringContext *v7; // rbx
  Scaleform::GFx::AS2::ActionBuffer *v8; // rax
  Scaleform::GFx::AS2::ActionBuffer *v9; // rax
  Scaleform::GFx::AS2::ActionBuffer *v10; // rbx

  v2 = this;
  v3 = (Scaleform::GFx::AS2::AvmSprite *)((char *)m + 4 * (unsigned __int8)m->AvmObjOffset);
  v4 = ((__int64 (__fastcall *)(char *))v3->vfptr[2].GetAbsolutePath)((char *)m + 4 * (unsigned __int8)m->AvmObjOffset);
  v5 = v2->pBuf.pObject;
  if ( v5 )
  {
    if ( v5->BufferLen >= 1 )
    {
      v6 = v5->pBuffer;
      if ( *v6 )
      {
        v7 = (Scaleform::GFx::AS2::ASStringContext *)(v4 + 232);
        v8 = (Scaleform::GFx::AS2::ActionBuffer *)(*(__int64 (__fastcall **)(char *, signed __int64))(**(_QWORD **)(*(_QWORD *)(v4 + 232) + 48i64) + 80i64))(
                                                    v6,
                                                    64i64);
        if ( v8 )
        {
          Scaleform::GFx::AS2::ActionBuffer::ActionBuffer(v8, v7, v2->pBuf.pObject);
          v10 = v9;
        }
        else
        {
          v10 = 0i64;
        }
        Scaleform::GFx::AS2::AvmSprite::AddActionBuffer(v3, v10, AP_Frame);
        if ( v10 )
          Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v10->vfptr);
      }
    }
  }
}

// File Line: 460
// RVA: 0x8CB190
void __fastcall Scaleform::GFx::AS2::DoActionTag::ExecuteWithPriority(Scaleform::GFx::AS2::DoActionTag *this, Scaleform::GFx::DisplayObjContainer *m, Scaleform::GFx::ActionPriority::Priority prio)
{
  Scaleform::GFx::ActionPriority::Priority v3; // esi
  Scaleform::GFx::AS2::DoActionTag *v4; // rbx
  Scaleform::GFx::AS2::AvmSprite *v5; // rdi
  Scaleform::GFx::AS2::ActionBufferData *v6; // rax
  __int64 v7; // rax
  Scaleform::GFx::AS2::ASStringContext *v8; // r14
  __int64 v9; // rcx
  Scaleform::GFx::AS2::ActionBuffer *v10; // rax
  Scaleform::GFx::AS2::ActionBuffer *v11; // rax
  Scaleform::GFx::AS2::ActionBuffer *v12; // rbx

  v3 = prio;
  v4 = this;
  v5 = (Scaleform::GFx::AS2::AvmSprite *)((char *)m + 4 * (unsigned __int8)m->AvmObjOffset);
  v6 = this->pBuf.pObject;
  if ( v6 && v6->BufferLen >= 1 && *v6->pBuffer )
  {
    v7 = ((__int64 (__fastcall *)(char *))v5->vfptr[2].GetAbsolutePath)((char *)m + 4 * (unsigned __int8)m->AvmObjOffset);
    v8 = (Scaleform::GFx::AS2::ASStringContext *)(v7 + 232);
    v10 = (Scaleform::GFx::AS2::ActionBuffer *)(*(__int64 (__fastcall **)(__int64, signed __int64))(**(_QWORD **)(*(_QWORD *)(v7 + 232) + 48i64)
                                                                                                  + 80i64))(
                                                 v9,
                                                 64i64);
    if ( v10 )
    {
      Scaleform::GFx::AS2::ActionBuffer::ActionBuffer(v10, v8, v4->pBuf.pObject);
      v12 = v11;
    }
    else
    {
      v12 = 0i64;
    }
    Scaleform::GFx::AS2::AvmSprite::AddActionBuffer(v5, v12, v3);
    if ( v12 )
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v12->vfptr);
  }
}

// File Line: 496
// RVA: 0x8C9440
void __fastcall Scaleform::GFx::AS2::DoInitActionTag::Execute(Scaleform::GFx::AS2::DoInitActionTag *this, Scaleform::GFx::DisplayObjContainer *m)
{
  Scaleform::GFx::AS2::DoInitActionTag *v2; // rbx
  Scaleform::GFx::AS2::ActionBufferData *v3; // rax
  Scaleform::GFx::AS2::AvmSprite *v4; // rdi
  __int64 v5; // rax
  Scaleform::GFx::AS2::ASStringContext *v6; // rsi
  __int64 v7; // rcx
  Scaleform::GFx::AS2::ActionBuffer *v8; // rax
  Scaleform::GFx::AS2::ActionBuffer *v9; // rax
  Scaleform::GFx::AS2::ActionBuffer *v10; // rbx

  v2 = this;
  v3 = this->pBuf.pObject;
  if ( v3 && v3->BufferLen >= 1 && *v3->pBuffer )
  {
    v4 = (Scaleform::GFx::AS2::AvmSprite *)((char *)m + 4 * (unsigned __int8)m->AvmObjOffset);
    v5 = ((__int64 (__fastcall *)(char *))v4->vfptr[2].GetAbsolutePath)((char *)m + 4 * (unsigned __int8)m->AvmObjOffset);
    v6 = (Scaleform::GFx::AS2::ASStringContext *)(v5 + 232);
    v8 = (Scaleform::GFx::AS2::ActionBuffer *)(*(__int64 (__fastcall **)(__int64, signed __int64))(**(_QWORD **)(*(_QWORD *)(v5 + 232) + 48i64)
                                                                                                 + 80i64))(
                                                v7,
                                                64i64);
    if ( v8 )
    {
      Scaleform::GFx::AS2::ActionBuffer::ActionBuffer(v8, v6, v2->pBuf.pObject);
      v10 = v9;
    }
    else
    {
      v10 = 0i64;
    }
    Scaleform::GFx::AS2::AvmSprite::AddActionBuffer(v4, v10, AP_InitClip);
    if ( v10 )
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v10->vfptr);
  }
}

// File Line: 517
// RVA: 0x8FAB60
void __fastcall Scaleform::GFx::AS2Support::ReadButtonActions(Scaleform::GFx::AS2Support *this, Scaleform::GFx::LoadProcess *p, Scaleform::GFx::ButtonDef *pbuttonDef, Scaleform::GFx::TagType tagType)
{
  Scaleform::GFx::TagType v4; // er14
  Scaleform::GFx::ButtonDef *v5; // rbp
  Scaleform::GFx::LoadProcess *v6; // rsi
  Scaleform::GFx::ButtonActionBase *v7; // rbx
  volatile int *v8; // ST30_8
  int v9; // edi
  signed __int64 v10; // rdx
  Scaleform::GFx::SWFProcessInfo *v11; // r8
  signed __int64 v12; // rcx
  __int64 v13; // rax

  v4 = tagType;
  v5 = pbuttonDef;
  v6 = p;
  v7 = (Scaleform::GFx::ButtonActionBase *)((__int64 (__fastcall *)(Scaleform::GFx::AS2Support *, signed __int64))p->pLoadData.pObject->pHeap->vfptr->Alloc)(
                                             this,
                                             48i64);
  if ( v7 )
  {
    v7->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
    v7->RefCount = 1;
    v7->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
    v7->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,258>::`vftable';
    v7->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::ButtonActionBase,258>::`vftable';
    v7->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ButtonActionBase::`vftable';
    v7->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS2::ButtonAction::`vftable';
    v8 = &v7[1].RefCount;
    v9 = 0;
    *(_QWORD *)v8 = 0i64;
    *((_QWORD *)v8 + 1) = 0i64;
    *((_QWORD *)v8 + 2) = 0i64;
  }
  else
  {
    v9 = 0;
    v7 = 0i64;
  }
  Scaleform::GFx::ButtonDef::AddButtonAction(v5, v7);
  v10 = (signed __int64)v6->pAltStream;
  v11 = &v6->ProcessInfo;
  if ( v10 )
  {
    v11 = (Scaleform::GFx::SWFProcessInfo *)v6->pAltStream;
    v12 = (signed __int64)v6->pAltStream;
  }
  else
  {
    v12 = (signed __int64)&v6->ProcessInfo;
  }
  v13 = (unsigned int)(*(_DWORD *)(v12 + 72) - 1);
  if ( (unsigned int)v13 < 2 )
    v9 = *(_DWORD *)(v12 + 4 * v13 + 64);
  if ( !v10 )
    v10 = (signed __int64)&v6->ProcessInfo;
  ((void (__fastcall *)(Scaleform::GFx::ButtonActionBase *, signed __int64, _QWORD, _QWORD))v7->vfptr[1].__vecDelDtor)(
    v7,
    v10,
    (unsigned int)v4,
    v9 + v11->Stream.DataSize - v11->Stream.FilePos - v11->Stream.Pos);
  Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v7);
}

// File Line: 526
// RVA: 0x8FA8F0
void __fastcall Scaleform::GFx::AS2Support::ReadButton2ActionConditions(Scaleform::GFx::AS2Support *this, Scaleform::GFx::LoadProcess *p, Scaleform::GFx::ButtonDef *pbuttonDef, Scaleform::GFx::TagType tagType)
{
  Scaleform::GFx::TagType v4; // er13
  Scaleform::GFx::LoadProcess *v5; // rsi
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy> *v6; // r12
  Scaleform::GFx::Stream *v7; // rbx
  __int64 v8; // r9
  unsigned __int16 v9; // r8
  int v10; // er15
  unsigned int v11; // er14
  int v12; // ebp
  __int64 v13; // rcx
  Scaleform::GFx::Resource *v14; // rbx
  _QWORD *v15; // rdi
  int v16; // er14
  Scaleform::GFx::ResourceVtbl *v17; // rdi
  Scaleform::GFx::SWFProcessInfo *v18; // rax
  signed int v19; // edi
  signed __int64 v20; // rdi
  int v21; // edx
  int v22; // eax
  int v23; // ecx
  signed __int64 v24; // [rsp+20h] [rbp-68h]
  Scaleform::GFx::Resource *v25; // [rsp+28h] [rbp-60h]
  signed __int64 v26; // [rsp+30h] [rbp-58h]

  v24 = -2i64;
  v4 = tagType;
  v5 = p;
  v6 = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy> *)&pbuttonDef->ButtonActions.Data.Data;
  while ( 1 )
  {
    v7 = v5->pAltStream;
    if ( !v7 )
      v7 = &v5->ProcessInfo.Stream;
    v7->UnusedBits = 0;
    if ( (signed int)(v7->DataSize - v7->Pos) < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(v7, 2);
    v8 = v7->Pos;
    v9 = (unsigned __int8)v7->pBuffer[v8] | (unsigned __int16)((unsigned __int8)v7->pBuffer[(unsigned int)(v8 + 1)] << 8);
    v7->Pos = v8 + 2;
    v10 = v9;
    v11 = v9 - 2;
    v12 = v11 + Scaleform::GFx::LoadProcess::Tell(v5);
    v14 = (Scaleform::GFx::Resource *)((__int64 (__fastcall *)(__int64, signed __int64))v5->pLoadData.pObject->pHeap->vfptr->Alloc)(
                                        v13,
                                        48i64);
    if ( v14 )
    {
      v14->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::RefCountImplCore::`vftable';
      v14->RefCount.Value = 1;
      v14->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::RefCountImpl::`vftable';
      v14->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,258>::`vftable';
      v14->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::ButtonActionBase,258>::`vftable';
      v14->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::ButtonActionBase::`vftable';
      v14->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::AS2::ButtonAction::`vftable';
      v25 = v14 + 1;
      v26 = (signed __int64)&v14[1];
      v25->vfptr = 0i64;
      *(_QWORD *)&v25->RefCount.Value = 0i64;
      v25->pLib = 0i64;
    }
    else
    {
      v14 = 0i64;
    }
    if ( v14 )
      Scaleform::Render::RenderBuffer::AddRef(v14);
    Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      v6,
      v6,
      v6->Size + 1);
    v15 = &v6->Data[v6->Size - 1].pObject;
    if ( v15 )
    {
      if ( v14 )
        Scaleform::Render::RenderBuffer::AddRef(v14);
      *v15 = v14;
    }
    if ( v14 )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v14);
    if ( !v10 )
    {
      v16 = Scaleform::GFx::LoadProcess::GetTagEndPosition(v5);
      v11 = v16 - Scaleform::GFx::LoadProcess::Tell(v5);
    }
    v17 = v14->vfptr;
    v18 = Scaleform::GFx::LoadProcess::GetStream(v5);
    ((void (__fastcall *)(Scaleform::GFx::Resource *, Scaleform::GFx::SWFProcessInfo *, _QWORD, _QWORD, signed __int64, Scaleform::GFx::Resource *, signed __int64, Scaleform::GFx::Resource *, Scaleform::GFx::Resource *))v17->GetKey)(
      v14,
      v18,
      (unsigned int)v4,
      v11,
      v24,
      v25,
      v26,
      v14,
      v14);
    if ( !v10 )
      break;
    v19 = Scaleform::GFx::LoadProcess::Tell(v5);
    if ( v19 >= (signed int)Scaleform::GFx::LoadProcess::GetTagEndPosition(v5) )
      break;
    v20 = (signed __int64)v5->pAltStream;
    if ( !v20 )
      v20 = (signed __int64)&v5->ProcessInfo;
    *(_BYTE *)(v20 + 41) = 0;
    v21 = *(_DWORD *)(v20 + 84);
    v22 = *(_DWORD *)(v20 + 80);
    v23 = *(_DWORD *)(v20 + 84) - v22;
    if ( v12 < v23 || v12 >= v21 )
    {
      if ( (*(_BYTE *)(v20 + 88) || *(_DWORD *)(v20 + 76) + v23 != v12)
        && (*(signed int (__fastcall **)(_QWORD, _QWORD, _QWORD))(**(_QWORD **)(v20 + 32) + 112i64))(
             *(_QWORD *)(v20 + 32),
             (unsigned int)v12,
             0i64) >= 0 )
      {
        *(_BYTE *)(v20 + 88) = 0;
        *(_QWORD *)(v20 + 76) = 0i64;
        *(_DWORD *)(v20 + 84) = v12;
      }
    }
    else
    {
      *(_DWORD *)(v20 + 76) = v12 + v22 - v21;
    }
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v14);
  }
  if ( v14 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v14);
}

// File Line: 551
// RVA: 0x8C77C0
void __fastcall Scaleform::GFx::AS2Support::DoActionLoader(Scaleform::GFx::AS2Support *this, Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::LoadProcess *v3; // rdi
  Scaleform::GFx::AS2::DoActionTag *v4; // rbx

  v3 = p;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&p->vfptr,
    "tag %d: DoActionLoader\n",
    (unsigned int)tagInfo->TagType);
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v3->vfptr,
    "-- actions in frame %d\n",
    v3->pLoadData.pObject->LoadingFrame);
  v4 = Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::AS2::DoActionTag>(v3);
  Scaleform::GFx::AS2::DoActionTag::Read(v4, v3);
  Scaleform::GFx::LoadProcess::AddExecuteTag(v3, (Scaleform::GFx::ExecuteTag *)&v4->vfptr);
}

// File Line: 564
// RVA: 0x8C7830
void __fastcall Scaleform::GFx::AS2Support::DoInitActionLoader(Scaleform::GFx::AS2Support *this, Scaleform::GFx::LoadProcess *p, Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::Stream *v3; // rbx
  Scaleform::GFx::TagInfo *v4; // r14
  Scaleform::GFx::LoadProcess *v5; // rsi
  unsigned int v6; // eax
  __int64 v7; // r9
  char *v8; // rdx
  __int16 v9; // r8
  __int16 v10; // ax
  unsigned int v11; // ebx
  Scaleform::GFx::AS2::DoInitActionTag *v12; // rbx
  Scaleform::GFx::ResourceId spriteId; // [rsp+38h] [rbp+10h]

  v3 = p->pAltStream;
  v4 = tagInfo;
  v5 = p;
  if ( !v3 )
    v3 = &p->ProcessInfo.Stream;
  v6 = v3->DataSize;
  v3->UnusedBits = 0;
  if ( (signed int)(v6 - v3->Pos) < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v3, 2);
  v7 = v3->Pos;
  v8 = v3->pBuffer;
  v9 = (unsigned __int8)v8[(unsigned int)(v7 + 1)];
  v10 = (unsigned __int8)v8[v7];
  v3->Pos = v7 + 2;
  v11 = (unsigned __int16)(v10 | (v9 << 8));
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v5->vfptr,
    "  tag %d: DoInitActionLoader\n",
    (unsigned int)v4->TagType);
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
    (Scaleform::GFx::LogBase<Scaleform::GFx::Stream> *)&v5->vfptr,
    "  -- init actions for sprite %d\n",
    v11);
  v12 = Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::AS2::DoInitActionTag>(v5);
  Scaleform::GFx::AS2::DoActionTag::Read((Scaleform::GFx::AS2::DoActionTag *)&v12->vfptr, v5);
  Scaleform::GFx::LoadProcess::AddInitAction(
    v5,
    (Scaleform::GFx::ResourceId)&spriteId,
    (Scaleform::GFx::ExecuteTag *)&v12->vfptr);
}

// File Line: 578
// RVA: 0x8B5C90
Scaleform::GFx::AS2::PlaceObject2EHa *__fastcall Scaleform::GFx::AS2Support::AllocPlaceObject2Tag(Scaleform::GFx::AS2Support *this, Scaleform::GFx::LoadProcess *p, unsigned __int64 dataSz, char swfVer)
{
  JUMPOUT(swfVer, 6, Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::AS2::PlaceObject2EH>);
  return Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::AS2::PlaceObject2EHa>(p, dataSz);
}

// File Line: 588
// RVA: 0x8B5CC0
Scaleform::GFx::AS2::PlaceObject3EH *__fastcall Scaleform::GFx::AS2Support::AllocPlaceObject3Tag(Scaleform::GFx::AS2Support *this, Scaleform::GFx::LoadProcess *p, unsigned __int64 dataSz)
{
  return Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::AS2::PlaceObject3EH>(p, dataSz);
}

// File Line: 593
// RVA: 0x8B5D00
Scaleform::GFx::AS2::RemoveObjectEH *__fastcall Scaleform::GFx::AS2Support::AllocRemoveObjectTag(Scaleform::GFx::AS2Support *this, Scaleform::GFx::LoadProcess *p)
{
  return Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::AS2::RemoveObjectEH>(p);
}

// File Line: 598
// RVA: 0x8B5CE0
Scaleform::GFx::AS2::RemoveObject2EH *__fastcall Scaleform::GFx::AS2Support::AllocRemoveObject2Tag(Scaleform::GFx::AS2Support *this, Scaleform::GFx::LoadProcess *p)
{
  return Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::AS2::RemoveObject2EH>(p);
}

