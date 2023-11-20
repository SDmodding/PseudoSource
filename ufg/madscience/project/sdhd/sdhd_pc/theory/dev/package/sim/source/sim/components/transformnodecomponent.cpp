// File Line: 42
// RVA: 0x14687F0
__int64 dynamic_initializer_for__UFG::TransformNodeComponent::sIdentityNode__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("TransformNodeComponent::sIdentityNode", 0xFFFFFFFF);
  UFG::TransformNodeComponent::TransformNodeComponent(&UFG::TransformNodeComponent::sIdentityNode, v0, 0i64, 0);
  return atexit(dynamic_atexit_destructor_for__UFG::TransformNodeComponent::sIdentityNode__);
}

// File Line: 53
// RVA: 0x18F1E0
void __fastcall UFG::TransformNodeComponent::TransformNodeComponent(UFG::TransformNodeComponent *this, unsigned int name_uid, UFG::TransformNodeComponent *parent, bool startSuspended)
{
  bool v4; // si
  UFG::TransformNodeComponent *v5; // rdi
  UFG::TransformNodeComponent *v6; // rbx
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v7; // r10
  float v8; // xmm1_4
  float v9; // xmm2_4
  UFG::SimObject *v10; // rcx
  __m128 v11; // xmm4
  __m128 v12; // xmm3
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v13; // rcx
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v14; // rax
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v15; // rax
  UFG::qList<UFG::TransformNodeComponent,UFG::TransformNodeComponent,1,0> *v16; // [rsp+50h] [rbp+18h]

  v4 = startSuspended;
  v5 = parent;
  v6 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v7 = (UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *)&v6->mPrev;
  v7->mPrev = v7;
  v7->mNext = v7;
  v6->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TransformNodeComponent::`vftable;
  v16 = &v6->mChildren;
  v16->mNode.mPrev = &v16->mNode;
  v16->mNode.mNext = &v16->mNode;
  v6->mChangeID = 0;
  v8 = UFG::qVector3::msZero.y;
  v9 = UFG::qVector3::msZero.z;
  v6->mWorldVelocity.x = UFG::qVector3::msZero.x;
  v6->mWorldVelocity.y = v8;
  v6->mWorldVelocity.z = v9;
  v6->mInheritXformType = 0;
  v6->m_TypeUID = UFG::TransformNodeComponent::_TransformNodeComponentTypeUID;
  v10 = v6->m_pSimObject;
  if ( v10 )
    v10->m_Components.p[v6->m_SimObjIndex].m_TypeUID = UFG::TransformNodeComponent::_TransformNodeComponentTypeUID;
  v11 = 0i64;
  v12 = 0i64;
  v12.m128_f32[0] = (float)1;
  v6->mLocalTransform.v0 = (UFG::qVector4)v12;
  v6->mLocalTransform.v1 = (UFG::qVector4)_mm_shuffle_ps(v12, v12, 81);
  v6->mLocalTransform.v2 = (UFG::qVector4)_mm_shuffle_ps(v12, v12, 69);
  v6->mLocalTransform.v3 = (UFG::qVector4)_mm_shuffle_ps(v12, v12, 21);
  v11.m128_f32[0] = (float)1;
  v6->mWorldTransform.v0 = (UFG::qVector4)v11;
  v6->mWorldTransform.v1 = (UFG::qVector4)_mm_shuffle_ps(v11, v11, 81);
  v6->mWorldTransform.v2 = (UFG::qVector4)_mm_shuffle_ps(v11, v11, 69);
  v6->mWorldTransform.v3 = (UFG::qVector4)_mm_shuffle_ps(v11, v11, 21);
  if ( v5 )
  {
    v13 = v7->mPrev;
    v14 = v6->mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v7->mPrev = v7;
    v6->mNext = (UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *)&v6->mPrev;
    v15 = v5->mChildren.mNode.mPrev;
    v15->mNext = v7;
    v7->mPrev = v15;
    v6->mNext = &v5->mChildren.mNode;
    v5->mChildren.mNode.mPrev = v7;
    v6->mParent = v5;
    v6->mChanged = -1;
    ++v6->mChangeID;
  }
  else
  {
    v6->mParent = 0i64;
    v6->mChanged = 0;
  }
  if ( v4 )
    v6->m_Flags |= 2u;
}

// File Line: 77
// RVA: 0x18FBF0
void __fastcall UFG::TransformNodeComponent::~TransformNodeComponent(UFG::TransformNodeComponent *this)
{
  UFG::TransformNodeComponent *v1; // r14
  UFG::qList<UFG::TransformNodeComponent,UFG::TransformNodeComponent,1,0> *v2; // rsi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **v3; // r15
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v4; // rdx
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v5; // rcx
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v6; // rax
  signed __int64 v7; // rdi
  __int128 v8; // xmm2
  __int128 v9; // xmm1
  __int128 v10; // xmm0
  UFG::TransformNodeComponent *i; // rbx
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v12; // rcx
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v13; // rax
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v14; // rdx
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v15; // rcx
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v16; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TransformNodeComponent::`vftable;
  v2 = &this->mChildren;
  if ( (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **)&this->mChildren.mNode.mNext[-4] != &this->m_SafePointerList.mNode.mNext )
  {
    v3 = &this->m_SafePointerList.mNode.mNext;
    do
    {
      v4 = v1->mChildren.mNode.mNext;
      v5 = v4->mPrev;
      v6 = v4->mNext;
      v5->mNext = v6;
      v6->mPrev = v5;
      v4->mPrev = v4;
      v4->mNext = v4;
      v7 = (signed __int64)&v4[-4];
      v4[2].mNext = 0i64;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)&v4[-4]);
      v8 = *(_OWORD *)(v7 + 144);
      v9 = *(_OWORD *)(v7 + 160);
      v10 = *(_OWORD *)(v7 + 176);
      *(_OWORD *)(v7 + 192) = *(_OWORD *)(v7 + 128);
      *(_OWORD *)(v7 + 208) = v8;
      *(_OWORD *)(v7 + 224) = v9;
      *(_OWORD *)(v7 + 240) = v10;
      *(_DWORD *)(v7 + 112) = -1;
      ++*(_DWORD *)(v7 + 96);
      for ( i = (UFG::TransformNodeComponent *)(*(_QWORD *)(v7 + 88) - 64i64);
            i != (UFG::TransformNodeComponent *)(v7 + 16);
            i = (UFG::TransformNodeComponent *)&i->mNext[-4] )
      {
        UFG::TransformNodeComponent::MarkForUpdateHelper((UFG::TransformNodeComponent *)v7, i);
      }
      *(_DWORD *)(v7 + 112) = -1;
      ++*(_DWORD *)(v7 + 96);
    }
    while ( (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **)&v2->mNode.mNext[-4] != v3 );
  }
  UFG::qList<UFG::TransformNodeComponent,UFG::TransformNodeComponent,1,0>::DeleteNodes(v2);
  v12 = v2->mNode.mPrev;
  v13 = v2->mNode.mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  v14 = (UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *)&v1->mPrev;
  v15 = v1->mPrev;
  v16 = v1->mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v14->mPrev = v14;
  v14->mNext = v14;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 100
// RVA: 0x191370
void __fastcall UFG::TransformNodeComponent::SetParent(UFG::TransformNodeComponent *this, UFG::TransformNodeComponent *new_parent, UFG::TransformNodeComponent::eInheritXformType inheritXformType)
{
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v3; // r8
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v4; // rax
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v5; // r10
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v6; // rax

  if ( this->mParent != new_parent )
  {
    this->mInheritXformType = inheritXformType;
    v3 = this->mPrev;
    v4 = this->mNext;
    v5 = (UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *)&this->mPrev;
    v3->mNext = v4;
    v4->mPrev = v3;
    v5->mPrev = v5;
    v5->mNext = v5;
    if ( new_parent )
    {
      v6 = new_parent->mChildren.mNode.mPrev;
      v6->mNext = v5;
      v5->mPrev = v6;
      this->mNext = &new_parent->mChildren.mNode;
      new_parent->mChildren.mNode.mPrev = v5;
    }
    ++this->mChangeID;
    this->mParent = new_parent;
    this->mChanged = -1;
  }
}

// File Line: 117
// RVA: 0x1913D0
void __fastcall UFG::TransformNodeComponent::SetParentKeepWorld(UFG::TransformNodeComponent *this, UFG::TransformNodeComponent *pParent, UFG::TransformNodeComponent::eInheritXformType inheritXformType)
{
  UFG::TransformNodeComponent *v3; // rdi
  UFG::TransformNodeComponent *v4; // rbx
  UFG::qMatrix44 *v5; // rdx
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v6; // rcx
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v7; // rax
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v8; // rdx
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v9; // rax
  UFG::qMatrix44 d; // [rsp+20h] [rbp-88h]
  UFG::qMatrix44 result; // [rsp+60h] [rbp-48h]

  v3 = pParent;
  v4 = this;
  if ( this->mParent != pParent )
  {
    this->mInheritXformType = inheritXformType;
    if ( pParent )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(pParent);
      UFG::qInverseAffine(&d, &v3->mWorldTransform);
      UFG::TransformNodeComponent::UpdateWorldTransform(v4);
      v5 = UFG::qMatrix44::operator*(&v4->mWorldTransform, &result, &d);
    }
    else
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(this);
      v5 = &v4->mWorldTransform;
    }
    UFG::TransformNodeComponent::SetLocalTransform(v4, v5);
    v6 = v4->mPrev;
    v7 = v4->mNext;
    v8 = (UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *)&v4->mPrev;
    v6->mNext = v7;
    v7->mPrev = v6;
    v8->mPrev = v8;
    v8->mNext = v8;
    if ( v3 )
    {
      v9 = v3->mChildren.mNode.mPrev;
      v9->mNext = v8;
      v8->mPrev = v9;
      v4->mNext = &v3->mChildren.mNode;
      v3->mChildren.mNode.mPrev = v8;
    }
    ++v4->mChangeID;
    v4->mParent = v3;
    v4->mChanged = -1;
  }
}

// File Line: 183
// RVA: 0x191D60
void __fastcall UFG::TransformNodeComponent::UpdateWorldTransform(UFG::TransformNodeComponent *this)
{
  UFG::TransformNodeComponent *v1; // rdx
  UFG::TransformNodeComponent *v2; // rdi
  UFG::qVector4 v3; // xmm3
  UFG::qVector4 v4; // xmm2
  UFG::qVector4 v5; // xmm1
  __int64 *v6; // r10
  int v7; // er9
  int v8; // er8
  int v9; // ecx
  int v10; // eax
  int v11; // ecx
  __int64 v12; // rax
  UFG::qVector4 v13; // xmm1
  UFG::qVector4 v14; // xmm0
  UFG::qVector4 v15; // xmm1
  __int64 v16; // rax
  UFG::qVector4 v17; // xmm4
  UFG::qVector4 v18; // xmm2
  UFG::qVector4 v19; // xmm1
  __int64 i; // r14
  __int64 v21; // rbx
  UFG::qMatrix44 *v22; // rax
  UFG::qVector4 v23; // xmm4
  UFG::qVector4 v24; // xmm2
  UFG::qVector4 v25; // xmm1
  UFG::TransformNodeComponent::eInheritXformType v26; // ecx
  float v27; // xmm2_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  UFG::qMatrix44 *v30; // rax
  UFG::qVector4 v31; // xmm3
  UFG::qVector4 v32; // xmm2
  UFG::qVector4 v33; // xmm1
  UFG::qMatrix44 b; // [rsp+20h] [rbp-E0h]
  UFG::qMatrix44 result; // [rsp+60h] [rbp-A0h]
  __int64 v36; // [rsp+A0h] [rbp-60h]
  __int64 v37[63]; // [rsp+A8h] [rbp-58h]

  v1 = this->mParent;
  v2 = this;
  if ( v1 )
  {
    v6 = &v36;
    v7 = 0;
    v8 = -1;
    do
    {
      v9 = v1->mChanged;
      *v6 = (__int64)v1;
      v1 = v1->mParent;
      v10 = v9;
      v11 = v7++ & v9;
      ++v6;
      v8 = v11 | ~v10 & v8;
    }
    while ( v1 );
    *(&v36 + v7) = 0i64;
    v12 = v37[v8];
    if ( v12 )
    {
      v13 = *(UFG::qVector4 *)(v12 + 144);
      b.v0 = *(UFG::qVector4 *)(v12 + 128);
      v14 = *(UFG::qVector4 *)(v12 + 160);
      b.v1 = v13;
      v15 = *(UFG::qVector4 *)(v12 + 176);
      b.v2 = v14;
      b.v3 = v15;
    }
    else
    {
      v16 = *(&v36 + v8--);
      v17 = *(UFG::qVector4 *)(v16 + 208);
      v18 = *(UFG::qVector4 *)(v16 + 240);
      b.v0 = *(UFG::qVector4 *)(v16 + 192);
      b.v1 = v17;
      b.v3 = v18;
      v19 = *(UFG::qVector4 *)(v16 + 224);
      *(UFG::qVector4 *)(v16 + 128) = b.v0;
      *(UFG::qVector4 *)(v16 + 144) = v17;
      b.v2 = v19;
      *(UFG::qVector4 *)(v16 + 160) = v19;
      *(UFG::qVector4 *)(v16 + 176) = v18;
      *(_DWORD *)(v16 + 112) = 0;
    }
    for ( i = v8; i >= 0; *(_DWORD *)(v21 + 112) = 0 )
    {
      v21 = *(&v36 + i);
      v22 = UFG::qMatrix44::operator*((UFG::qMatrix44 *)(v21 + 192), &result, &b);
      --i;
      v23 = v22->v1;
      v24 = v22->v3;
      b.v0 = v22->v0;
      b.v1 = v23;
      b.v3 = v24;
      v25 = v22->v2;
      *(UFG::qVector4 *)(v21 + 128) = b.v0;
      *(UFG::qVector4 *)(v21 + 144) = v23;
      b.v2 = v25;
      *(UFG::qVector4 *)(v21 + 160) = v25;
      *(UFG::qVector4 *)(v21 + 176) = v24;
    }
    v26 = v2->mInheritXformType;
    if ( v26 )
    {
      if ( v26 == 1 )
      {
        v27 = b.v3.x + v2->mLocalTransform.v3.x;
        v28 = b.v3.y + v2->mLocalTransform.v3.y;
        v29 = b.v3.z + v2->mLocalTransform.v3.z;
        v2->mWorldTransform.v3.w = 1.0;
        v2->mWorldTransform.v3.x = v27;
        v2->mWorldTransform.v3.y = v28;
        v2->mWorldTransform.v3.z = v29;
      }
    }
    else
    {
      v30 = UFG::qMatrix44::operator*(&v2->mLocalTransform, &result, &b);
      v31 = v30->v1;
      v32 = v30->v2;
      v33 = v30->v3;
      v2->mWorldTransform.v0 = v30->v0;
      v2->mWorldTransform.v1 = v31;
      v2->mWorldTransform.v2 = v32;
      v2->mWorldTransform.v3 = v33;
    }
    v2->mChanged = 0;
  }
  else if ( this->mChanged )
  {
    v3 = this->mLocalTransform.v1;
    v4 = this->mLocalTransform.v2;
    v5 = this->mLocalTransform.v3;
    this->mWorldTransform.v0 = this->mLocalTransform.v0;
    this->mWorldTransform.v1 = v3;
    this->mWorldTransform.v2 = v4;
    this->mWorldTransform.v3 = v5;
    this->mChanged = 0;
  }
}

// File Line: 281
// RVA: 0x190D20
void __fastcall UFG::TransformNodeComponent::MarkForUpdateHelper(UFG::TransformNodeComponent *this, UFG::TransformNodeComponent *node)
{
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v2; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **v3; // rdi
  UFG::TransformNodeComponent *v4; // rbx
  UFG::TransformNodeComponent *v5; // rsi

  v2 = node->mChildren.mNode.mNext;
  ++node->mChangeID;
  v3 = &node->m_SafePointerList.mNode.mNext;
  v4 = (UFG::TransformNodeComponent *)&v2[-4];
  v5 = this;
  node->mChanged = -1;
  if ( v4 != (UFG::TransformNodeComponent *)&node->m_SafePointerList.mNode.mNext )
  {
    do
    {
      UFG::TransformNodeComponent::MarkForUpdateHelper(v5, v4);
      v4 = (UFG::TransformNodeComponent *)&v4->mNext[-4];
    }
    while ( v4 != (UFG::TransformNodeComponent *)v3 );
  }
}

// File Line: 299
// RVA: 0x191250
void __fastcall UFG::TransformNodeComponent::SetLocalTransform(UFG::TransformNodeComponent *this, UFG::qMatrix44 *m)
{
  UFG::qVector4 v2; // xmm3
  UFG::qVector4 v3; // xmm2
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **v4; // rsi
  UFG::TransformNodeComponent *v5; // rdi
  UFG::qVector4 v6; // xmm1
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v7; // rbx
  UFG::TransformNodeComponent *v8; // rbx

  v2 = m->v1;
  v3 = m->v2;
  v4 = &this->m_SafePointerList.mNode.mNext;
  v5 = this;
  v6 = m->v3;
  this->mLocalTransform.v0 = m->v0;
  this->mLocalTransform.v1 = v2;
  this->mLocalTransform.v2 = v3;
  this->mLocalTransform.v3 = v6;
  v7 = this->mChildren.mNode.mNext;
  ++this->mChangeID;
  this->mChanged = -1;
  v8 = (UFG::TransformNodeComponent *)&v7[-4];
  if ( v8 != (UFG::TransformNodeComponent *)&this->m_SafePointerList.mNode.mNext )
  {
    do
    {
      UFG::TransformNodeComponent::MarkForUpdateHelper(v5, v8);
      v8 = (UFG::TransformNodeComponent *)&v8->mNext[-4];
    }
    while ( v8 != (UFG::TransformNodeComponent *)v4 );
  }
}

// File Line: 309
// RVA: 0x1912E0
void __fastcall UFG::TransformNodeComponent::SetLocalTranslation(UFG::TransformNodeComponent *this, UFG::qVector3 *pos)
{
  float v2; // eax
  float v3; // xmm0_4
  float v4; // xmm1_4
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **v5; // rsi
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v6; // rbx
  UFG::TransformNodeComponent *v7; // rdi
  UFG::TransformNodeComponent *v8; // rbx

  v2 = pos->x;
  v3 = pos->y;
  v4 = pos->z;
  this->mLocalTransform.v3.w = 1.0;
  this->mLocalTransform.v3.x = v2;
  v5 = &this->m_SafePointerList.mNode.mNext;
  this->mLocalTransform.v3.y = v3;
  this->mLocalTransform.v3.z = v4;
  v6 = this->mChildren.mNode.mNext;
  ++this->mChangeID;
  v7 = this;
  v8 = (UFG::TransformNodeComponent *)&v6[-4];
  this->mChanged = -1;
  if ( v8 != (UFG::TransformNodeComponent *)&this->m_SafePointerList.mNode.mNext )
  {
    do
    {
      UFG::TransformNodeComponent::MarkForUpdateHelper(v7, v8);
      v8 = (UFG::TransformNodeComponent *)&v8->mNext[-4];
    }
    while ( v8 != (UFG::TransformNodeComponent *)v5 );
  }
}

// File Line: 319
// RVA: 0x1914B0
void __fastcall UFG::TransformNodeComponent::SetWorldTransform(UFG::TransformNodeComponent *this, UFG::qMatrix44 *m)
{
  UFG::TransformNodeComponent *v2; // rdi
  UFG::qMatrix44 *v3; // rsi
  UFG::TransformNodeComponent *v4; // rbx
  UFG::qMatrix44 *v5; // rax
  UFG::qMatrix44 d; // [rsp+20h] [rbp-88h]
  UFG::qMatrix44 result; // [rsp+60h] [rbp-48h]

  v2 = this->mParent;
  v3 = m;
  v4 = this;
  if ( v2 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v2);
    UFG::qInverseAffine(&d, &v2->mWorldTransform);
    v5 = UFG::qMatrix44::operator*(v3, &result, &d);
    this = v4;
    m = v5;
  }
  UFG::TransformNodeComponent::SetLocalTransform(this, m);
}

// File Line: 336
// RVA: 0x191520
void __fastcall UFG::TransformNodeComponent::SetWorldTranslation(UFG::TransformNodeComponent *this, UFG::qVector3 *pos)
{
  UFG::TransformNodeComponent *v2; // rsi
  UFG::qVector3 *v3; // rbx
  UFG::TransformNodeComponent *v4; // rdi
  float v5; // xmm4_4
  float v6; // xmm7_4
  float v7; // xmm3_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm3_4
  float v11; // xmm2_4
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v12; // rbx
  UFG::TransformNodeComponent *i; // rbx
  UFG::qMatrix44 d; // [rsp+20h] [rbp-58h]

  v2 = this->mParent;
  v3 = pos;
  v4 = this;
  if ( v2 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(this->mParent);
    UFG::qInverseAffine(&d, &v2->mWorldTransform);
    v5 = v3->y;
    v6 = (float)((float)((float)(d.v1.x * v5) + (float)(d.v0.x * v3->x)) + (float)(d.v2.x * v3->z)) + d.v3.x;
    v7 = (float)((float)(d.v1.y * v5) + (float)(d.v0.y * v3->x)) + (float)(d.v2.y * v3->z);
    v8 = (float)(d.v1.z * v5) + (float)(d.v0.z * v3->x);
    v9 = d.v2.z * v3->z;
    v4->mLocalTransform.v3.w = 1.0;
    v10 = v7 + d.v3.y;
    v4->mLocalTransform.v3.x = v6;
    v11 = (float)(v8 + v9) + d.v3.z;
    v4->mLocalTransform.v3.y = v10;
    v4->mLocalTransform.v3.z = v11;
    v12 = v4->mChildren.mNode.mNext;
    ++v4->mChangeID;
    v4->mChanged = -1;
    for ( i = (UFG::TransformNodeComponent *)&v12[-4];
          i != (UFG::TransformNodeComponent *)&v4->m_SafePointerList.mNode.mNext;
          i = (UFG::TransformNodeComponent *)&i->mNext[-4] )
    {
      UFG::TransformNodeComponent::MarkForUpdateHelper(v4, i);
    }
  }
  else
  {
    UFG::TransformNodeComponent::SetLocalTranslation(this, pos);
  }
}

// File Line: 378
// RVA: 0x191720
void __fastcall UFG::TransformNodeComponent::TeleportEventHandler(UFG::TransformNodeComponent *this, UFG::Event *this_event)
{
  UFG::TransformNodeComponent *v2; // rdi
  UFG::TransformNodeComponent *v3; // rbx
  UFG::qMatrix44 *v4; // rsi
  UFG::qMatrix44 *v5; // rdx
  UFG::qMatrix44 *v6; // rax
  UFG::qMatrix44 d; // [rsp+20h] [rbp-88h]
  UFG::qMatrix44 result; // [rsp+60h] [rbp-48h]

  v2 = this->mParent;
  v3 = this;
  v4 = (UFG::qMatrix44 *)&this_event[1].m_EventUID;
  if ( v2 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v2);
    UFG::qInverseAffine(&d, &v2->mWorldTransform);
    v6 = UFG::qMatrix44::operator*(v4, &result, &d);
    this = v3;
    v5 = v6;
  }
  else
  {
    v5 = (UFG::qMatrix44 *)&this_event[1].m_EventUID;
  }
  UFG::TransformNodeComponent::SetLocalTransform(this, v5);
  UFG::TransformNodeComponent::UpdateWorldTransform(v3);
}

// File Line: 518
// RVA: 0x190E10
void __fastcall UFG::TransformNodeComponent::PropertiesLoadWithMatrix(UFG::TransformNodeComponent *this, UFG::SceneObjectProperties *pSceneObj, UFG::qMatrix44 *pWorldMatrix)
{
  UFG::SceneObjectProperties *v3; // rsi
  UFG::TransformNodeComponent *v4; // rbx
  UFG::qMatrix44 *v5; // rax
  unsigned int *v6; // rax
  unsigned int v7; // edx
  UFG::TransformNodeComponent *v8; // rdi
  UFG::SceneObjectProperties *v9; // rax
  UFG::SimObject *v10; // rax
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v11; // rcx
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v12; // rax
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v13; // rdx
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v14; // rax

  v3 = pSceneObj;
  v4 = this;
  if ( pWorldMatrix )
  {
    UFG::TransformNodeComponent::SetLocalTransform(this, pWorldMatrix);
  }
  else
  {
    v5 = PropertyUtils::Get<UFG::qMatrix44>(pSceneObj, (UFG::qSymbol *)&qSymbol_XformLocal.mUID);
    UFG::TransformNodeComponent::SetLocalTransform(v4, v5);
    v6 = PropertyUtils::Get<unsigned long>(v3, (UFG::qSymbol *)&qSymbol_XformParent.mUID);
    if ( v6 )
      v7 = *v6;
    else
      v7 = 0;
    if ( !v3 )
    {
      v3 = (UFG::SceneObjectProperties *)v4->m_pSimObject;
      if ( v3 )
        v3 = (UFG::SceneObjectProperties *)v3->mpOwner.mPrev;
    }
    v8 = 0i64;
    if ( v7 )
    {
      v9 = UFG::SceneObjectProperties::GetAncestor(v3, v7);
      if ( v9 )
      {
        v10 = v9->m_pSimObject;
        if ( v10 )
          v8 = v10->m_pTransformNodeComponent;
      }
    }
    if ( v4->mParent != v8 )
    {
      v4->mInheritXformType = 0;
      v11 = v4->mPrev;
      v12 = v4->mNext;
      v13 = (UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *)&v4->mPrev;
      v11->mNext = v12;
      v12->mPrev = v11;
      v13->mPrev = v13;
      v13->mNext = v13;
      if ( v8 )
      {
        v14 = v8->mChildren.mNode.mPrev;
        v14->mNext = v13;
        v13->mPrev = v14;
        v4->mNext = &v8->mChildren.mNode;
        v8->mChildren.mNode.mPrev = v13;
      }
      ++v4->mChangeID;
      v4->mParent = v8;
      v4->mChanged = -1;
    }
  }
}

// File Line: 549
// RVA: 0x190E00
void __fastcall UFG::TransformNodeComponent::PropertiesLoad(UFG::TransformNodeComponent *this, UFG::SceneObjectProperties *pSceneObj)
{
  UFG::TransformNodeComponent::PropertiesLoadWithMatrix(this, pSceneObj, 0i64);
}

