// File Line: 36
// RVA: 0x22F760
void __fastcall SectionEffects::SectionEffects(SectionEffects *this)
{
  SectionEffects *v1; // rdi
  unsigned int v2; // esi
  signed __int64 v3; // rax
  UFG::qResourceHandle *v4; // rbx
  UFG::qResourceInventory *v5; // rax
  UFG::qResourceWarehouse *v6; // rax

  v1 = this;
  UFG::qResourceData::qResourceData((UFG::qResourceData *)&this->mNode);
  v2 = 0;
  if ( v1->mEffectsCount )
  {
    do
    {
      v3 = 120i64 * v2;
      v4 = (UFG::qResourceHandle *)((char *)&v1[1] + v3);
      if ( (SectionEffects *)((char *)&v1[1] + v3) )
        UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)((char *)&v1[1] + v3));
      v5 = `UFG::qGetResourceInventory<Render::FXSettings>::`2::result;
      if ( !`UFG::qGetResourceInventory<Render::FXSettings>::`2::result )
      {
        v6 = UFG::qResourceWarehouse::Instance();
        v5 = UFG::qResourceWarehouse::GetInventory(v6, 0xED341A8D);
        `UFG::qGetResourceInventory<Render::FXSettings>::`2::result = v5;
      }
      UFG::qResourceHandle::Init(v4, 0xED341A8D, v4->mNameUID, v5);
      ++v2;
    }
    while ( v2 < v1->mEffectsCount );
  }
}

// File Line: 45
// RVA: 0x22FC60
void __fastcall SectionEffects::~SectionEffects(SectionEffects *this)
{
  SectionEffects *v1; // rsi
  unsigned int v2; // edi
  UFG::qResourceHandle *v3; // rbx
  UFG::qResourceInventory *v4; // rax
  UFG::qResourceWarehouse *v5; // rax
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v6; // rdi
  UFG::qResourceHandle *v7; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v8; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v9; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v10; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v11; // rax

  v1 = this;
  v2 = 0;
  if ( this->mEffectsCount )
  {
    do
    {
      v3 = (UFG::qResourceHandle *)((char *)&v1[1] + 120 * v2);
      v4 = `UFG::qGetResourceInventory<Render::FXSettings>::`2::result;
      if ( !`UFG::qGetResourceInventory<Render::FXSettings>::`2::result )
      {
        v5 = UFG::qResourceWarehouse::Instance();
        v4 = UFG::qResourceWarehouse::GetInventory(v5, 0xED341A8D);
        `UFG::qGetResourceInventory<Render::FXSettings>::`2::result = v4;
      }
      UFG::qResourceHandle::Close(v3, v4);
      UFG::qResourceHandle::~qResourceHandle(v3);
      ++v2;
    }
    while ( v2 < v1->mEffectsCount );
  }
  v6 = &v1->mResourceHandles;
  v7 = (UFG::qResourceHandle *)v1->mResourceHandles.mNode.mNext;
  if ( v7 != (UFG::qResourceHandle *)&v1->mResourceHandles )
  {
    do
    {
      v8 = v7->mPrev;
      v9 = v7->mNext;
      v8->mNext = v9;
      v9->mPrev = v8;
      v7->mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&v7->mPrev;
      v7->mNext = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&v7->mPrev;
      UFG::qResourceHandle::~qResourceHandle(v7);
      operator delete[](v7);
      v7 = (UFG::qResourceHandle *)v1->mResourceHandles.mNode.mNext;
    }
    while ( v7 != (UFG::qResourceHandle *)v6 );
  }
  v10 = v6->mNode.mPrev;
  v11 = v1->mResourceHandles.mNode.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v6->mNode.mPrev = &v6->mNode;
  v1->mResourceHandles.mNode.mNext = &v1->mResourceHandles.mNode;
}

// File Line: 66
// RVA: 0x1470390
__int64 dynamic_initializer_for__gSectionEffectsInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&gSectionEffectsInventory.vfptr,
    "SectionEffectsInventory",
    0x468D9324u,
    0x89A7BDF7,
    0,
    0);
  gSectionEffectsInventory.vfptr = (UFG::qResourceInventoryVtbl *)&SectionEffectsInventory::`vftable;
  return atexit(dynamic_atexit_destructor_for__gSectionEffectsInventory__);
}

// File Line: 74
// RVA: 0x230220
void __fastcall SectionEffectsInventory::Add(SectionEffectsInventory *this, UFG::qResourceData *data)
{
  UFG::qResourceData *v2; // rbx
  SectionEffectsInventory *v3; // rdi

  v2 = data;
  v3 = this;
  if ( data )
    SectionEffects::SectionEffects((SectionEffects *)data);
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v3->vfptr, v2);
}

// File Line: 82
// RVA: 0x234F70
void __fastcall SectionEffectsInventory::Remove(SectionEffectsInventory *this, UFG::qResourceData *data)
{
  SectionEffects *v2; // rsi
  unsigned int v3; // ebx
  signed __int64 v4; // rdi
  unsigned int v5; // edx

  v2 = (SectionEffects *)data;
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&this->vfptr, data);
  v3 = 0;
  if ( v2->mEffectsCount )
  {
    do
    {
      v4 = 15i64 * v3;
      v5 = (unsigned int)v2[2].mNode.mChild[v4 + 1];
      if ( v5 != -1 )
      {
        Render::FXManager::KillEffect(&Render::gFXManager, v5, 0);
        LODWORD(v2[2].mNode.mChild[v4 + 1]) = -1;
      }
      ++v3;
    }
    while ( v3 < v2->mEffectsCount );
  }
  SectionEffects::~SectionEffects(v2);
}

// File Line: 106
// RVA: 0x2359F0
void __fastcall UpdateSectionEffects(UFG::qVector3 *camPos, float secsSinceMidnight)
{
  UFG::qVector3 *v2; // r14
  float v3; // xmm8_4
  UFG::qBaseNodeRB *i; // rsi
  unsigned int j; // edi
  signed __int64 v6; // rbx
  float v7; // xmm3_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  unsigned int v11; // edx

  v2 = camPos;
  v3 = secsSinceMidnight;
  for ( i = (UFG::qBaseNodeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_1423A92A0);
        i;
        i = (UFG::qBaseNodeRB *)UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_1423A92A0, i) )
  {
    for ( j = 0; j < i[2].mUID; ++j )
    {
      v6 = (signed __int64)&i[3] + 120 * j;
      if ( *(_QWORD *)(v6 + 16) )
      {
        v7 = *(float *)(v6 + 104);
        v8 = *(float *)(v6 + 108) - v7;
        v9 = (float)((float)((float)(*(float *)(v6 + 84) - v2->y) * (float)(*(float *)(v6 + 84) - v2->y))
                   + (float)((float)(*(float *)(v6 + 80) - v2->x) * (float)(*(float *)(v6 + 80) - v2->x)))
           + (float)((float)(*(float *)(v6 + 88) - v2->z) * (float)(*(float *)(v6 + 88) - v2->z));
        if ( v8 < 0.0 )
          v8 = v8 + 86400.0;
        v10 = v3 - v7;
        if ( (float)(v3 - v7) < 0.0 )
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
          Render::FXManager::KillEffect(&Render::gFXManager, v11, 0);
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
  unsigned int v1; // ebx
  signed __int64 v2; // rdi
  unsigned int v3; // edx

  for ( i = (UFG::qBaseNodeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_1423A92A0);
        i;
        i = (UFG::qBaseNodeRB *)UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_1423A92A0, i) )
  {
    v1 = 0;
    if ( i[2].mUID )
    {
      do
      {
        v2 = 15i64 * v1;
        v3 = (unsigned int)i[6].mChild[v2 + 1];
        if ( v3 != -1 )
        {
          Render::FXManager::KillEffect(&Render::gFXManager, v3, 0);
          LODWORD(i[6].mChild[v2 + 1]) = -1;
        }
        ++v1;
      }
      while ( v1 < i[2].mUID );
    }
  }
}

