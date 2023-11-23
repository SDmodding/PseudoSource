// File Line: 36
// RVA: 0x22F760
void __fastcall SectionEffects::SectionEffects(SectionEffects *this)
{
  unsigned int i; // esi
  __int64 v3; // rax
  UFG::qResourceHandle *v4; // rbx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v6; // rax

  UFG::qResourceData::qResourceData(this);
  for ( i = 0; i < this->mEffectsCount; ++i )
  {
    v3 = 120i64 * i;
    v4 = (UFG::qResourceHandle *)((char *)&this[1] + v3);
    if ( v4 )
      UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)((char *)&this[1] + v3));
    Inventory = `UFG::qGetResourceInventory<Render::FXSettings>::`2::result;
    if ( !`UFG::qGetResourceInventory<Render::FXSettings>::`2::result )
    {
      v6 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v6, 0xED341A8D);
      `UFG::qGetResourceInventory<Render::FXSettings>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Init(v4, 0xED341A8D, v4->mNameUID, Inventory);
  }
}

// File Line: 45
// RVA: 0x22FC60
void __fastcall SectionEffects::~SectionEffects(SectionEffects *this)
{
  unsigned int i; // edi
  UFG::qResourceHandle *v3; // rbx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v5; // rax
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *p_mResourceHandles; // rdi
  UFG::qResourceHandle *mNext; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v9; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v10; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v11; // rax

  for ( i = 0; i < this->mEffectsCount; ++i )
  {
    v3 = (UFG::qResourceHandle *)((char *)&this[1] + 120 * i);
    Inventory = `UFG::qGetResourceInventory<Render::FXSettings>::`2::result;
    if ( !`UFG::qGetResourceInventory<Render::FXSettings>::`2::result )
    {
      v5 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v5, 0xED341A8D);
      `UFG::qGetResourceInventory<Render::FXSettings>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Close(v3, Inventory);
    UFG::qResourceHandle::~qResourceHandle(v3);
  }
  p_mResourceHandles = &this->mResourceHandles;
  mNext = (UFG::qResourceHandle *)this->mResourceHandles.UFG::qResourceData::mNode.mNext;
  if ( mNext != (UFG::qResourceHandle *)&this->mResourceHandles )
  {
    do
    {
      mPrev = mNext->mPrev;
      v9 = mNext->mNext;
      mPrev->mNext = v9;
      v9->mPrev = mPrev;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      UFG::qResourceHandle::~qResourceHandle(mNext);
      operator delete[](mNext);
      mNext = (UFG::qResourceHandle *)this->mResourceHandles.UFG::qResourceData::mNode.mNext;
    }
    while ( mNext != (UFG::qResourceHandle *)p_mResourceHandles );
  }
  v10 = p_mResourceHandles->mNode.mPrev;
  v11 = this->mResourceHandles.UFG::qResourceData::mNode.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_mResourceHandles->mNode.mPrev = &p_mResourceHandles->mNode;
  this->mResourceHandles.UFG::qResourceData::mNode.mNext = &this->mResourceHandles.UFG::qResourceData::mNode;
}

// File Line: 66
// RVA: 0x1470390
__int64 dynamic_initializer_for__gSectionEffectsInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &gSectionEffectsInventory,
    "SectionEffectsInventory",
    0x468D9324u,
    0x89A7BDF7,
    0,
    0);
  gSectionEffectsInventory.vfptr = (UFG::qResourceInventoryVtbl *)&SectionEffectsInventory::`vftable;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gSectionEffectsInventory__);
}

// File Line: 74
// RVA: 0x230220
void __fastcall SectionEffectsInventory::Add(SectionEffectsInventory *this, SectionEffects *data)
{
  if ( data )
    SectionEffects::SectionEffects(data);
  UFG::qResourceInventory::Add(this, data);
}

// File Line: 82
// RVA: 0x234F70
void __fastcall SectionEffectsInventory::Remove(SectionEffectsInventory *this, SectionEffects *data)
{
  unsigned int i; // ebx
  __int64 v4; // rdi
  unsigned int v5; // edx

  UFG::qResourceInventory::Remove(this, data);
  for ( i = 0; i < data->mEffectsCount; ++i )
  {
    v4 = 15i64 * i;
    v5 = (unsigned int)data[2].mNode.mChild[v4 + 1];
    if ( v5 != -1 )
    {
      Render::FXManager::KillEffect(&Render::gFXManager, v5, FXKILLOPTION_DEFAULT);
      LODWORD(data[2].mNode.mChild[v4 + 1]) = -1;
    }
  }
  SectionEffects::~SectionEffects(data);
}

// File Line: 106
// RVA: 0x2359F0
void __fastcall UpdateSectionEffects(UFG::qVector3 *camPos, float secsSinceMidnight)
{
  UFG::qBaseNodeRB *i; // rsi
  unsigned int j; // edi
  __int64 v6; // rbx
  float v7; // xmm3_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  unsigned int v11; // edx

  for ( i = (UFG::qBaseNodeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_1423A92A0);
        i;
        i = (UFG::qBaseNodeRB *)UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_1423A92A0, i) )
  {
    for ( j = 0; j < i[2].mUID; ++j )
    {
      v6 = (__int64)&i[3] + 120 * j;
      if ( *(_QWORD *)(v6 + 16) )
      {
        v7 = *(float *)(v6 + 104);
        v8 = *(float *)(v6 + 108) - v7;
        v9 = (float)((float)((float)(*(float *)(v6 + 84) - camPos->y) * (float)(*(float *)(v6 + 84) - camPos->y))
                   + (float)((float)(*(float *)(v6 + 80) - camPos->x) * (float)(*(float *)(v6 + 80) - camPos->x)))
           + (float)((float)(*(float *)(v6 + 88) - camPos->z) * (float)(*(float *)(v6 + 88) - camPos->z));
        if ( v8 < 0.0 )
          v8 = v8 + 86400.0;
        v10 = secsSinceMidnight - v7;
        if ( (float)(secsSinceMidnight - v7) < 0.0 )
          v10 = v10 + 86400.0;
        v11 = *(_DWORD *)(v6 + 112);
        if ( v11 == -1 )
        {
          if ( v10 <= v8 && v9 < *(float *)(v6 + 96) )
            *(_DWORD *)(v6 + 112) = Render::FXManager::CreateEffect(
                                      &Render::gFXManager,
                                      *(_DWORD *)(v6 + 24),
                                      (UFG::qMatrix44 *)(v6 + 32),
                                      0xFFFFFFFF);
        }
        else if ( v9 > *(float *)(v6 + 100) || v10 > v8 )
        {
          Render::FXManager::KillEffect(&Render::gFXManager, v11, FXKILLOPTION_DEFAULT);
          *(_DWORD *)(v6 + 112) = -1;
        }
      }
    }
  }
}

// File Line: 196
// RVA: 0x233370
void KillAllSectionEffects(void)
{
  UFG::qBaseNodeRB *i; // rsi
  unsigned int j; // ebx
  __int64 v2; // rdi
  unsigned int v3; // edx

  for ( i = (UFG::qBaseNodeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_1423A92A0);
        i;
        i = (UFG::qBaseNodeRB *)UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_1423A92A0, i) )
  {
    for ( j = 0; j < i[2].mUID; ++j )
    {
      v2 = 15i64 * j;
      v3 = (unsigned int)i[6].mChild[v2 + 1];
      if ( v3 != -1 )
      {
        Render::FXManager::KillEffect(&Render::gFXManager, v3, FXKILLOPTION_DEFAULT);
        LODWORD(i[6].mChild[v2 + 1]) = -1;
      }
    }
  }
}

