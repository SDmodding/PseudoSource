// File Line: 42
// RVA: 0x14687F0
__int64 dynamic_initializer_for__UFG::TransformNodeComponent::sIdentityNode__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("TransformNodeComponent::sIdentityNode", 0xFFFFFFFF);
  UFG::TransformNodeComponent::TransformNodeComponent(&UFG::TransformNodeComponent::sIdentityNode, v0, 0i64, 0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::TransformNodeComponent::sIdentityNode__);
}

// File Line: 53
// RVA: 0x18F1E0
void __fastcall UFG::TransformNodeComponent::TransformNodeComponent(
        UFG::TransformNodeComponent *this,
        unsigned int name_uid,
        UFG::TransformNodeComponent *parent,
        bool startSuspended)
{
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v7; // r10
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::SimObject *m_pSimObject; // rcx
  UFG::qVector4 v11; // xmm4
  UFG::qVector4 v12; // xmm3
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *mPrev; // rcx
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *mNext; // rax
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v15; // rax

  UFG::SimComponent::SimComponent(this, name_uid);
  v7 = &this->UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent>;
  this->mPrev = &this->UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent>;
  this->mNext = &this->UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TransformNodeComponent::`vftable;
  this->mChildren.mNode.mPrev = &this->mChildren.mNode;
  this->mChildren.mNode.mNext = &this->mChildren.mNode;
  this->mChangeID = 0;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mWorldVelocity.x = UFG::qVector3::msZero.x;
  this->mWorldVelocity.y = y;
  this->mWorldVelocity.z = z;
  this->mInheritXformType = eInheritXform_Full;
  this->m_TypeUID = UFG::TransformNodeComponent::_TransformNodeComponentTypeUID;
  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
    m_pSimObject->m_Components.p[this->m_SimObjIndex].m_TypeUID = UFG::TransformNodeComponent::_TransformNodeComponentTypeUID;
  v11 = 0i64;
  v12 = 0i64;
  v12.x = (float)1;
  this->mLocalTransform.v0 = v12;
  this->mLocalTransform.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v12, (__m128)v12, 81);
  this->mLocalTransform.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v12, (__m128)v12, 69);
  this->mLocalTransform.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v12, (__m128)v12, 21);
  v11.x = (float)1;
  this->mWorldTransform.v0 = v11;
  this->mWorldTransform.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v11, (__m128)v11, 81);
  this->mWorldTransform.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v11, (__m128)v11, 69);
  this->mWorldTransform.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v11, (__m128)v11, 21);
  if ( parent )
  {
    mPrev = v7->mPrev;
    mNext = this->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    v7->mPrev = v7;
    this->mNext = &this->UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent>;
    v15 = parent->mChildren.mNode.mPrev;
    v15->mNext = v7;
    v7->mPrev = v15;
    this->mNext = &parent->mChildren.mNode;
    parent->mChildren.mNode.mPrev = v7;
    this->mParent = parent;
    this->mChanged = -1;
    ++this->mChangeID;
  }
  else
  {
    this->mParent = 0i64;
    this->mChanged = 0;
  }
  if ( startSuspended )
    this->m_Flags |= 2u;
}

// File Line: 77
// RVA: 0x18FBF0
void __fastcall UFG::TransformNodeComponent::~TransformNodeComponent(UFG::TransformNodeComponent *this)
{
  UFG::qList<UFG::TransformNodeComponent,UFG::TransformNodeComponent,1,0> *p_mChildren; // rsi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **p_mNext; // r15
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *mNext; // rdx
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *mPrev; // rcx
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v6; // rax
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v7; // rdi
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> v8; // xmm2
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> v9; // xmm1
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> v10; // xmm0
  UFG::TransformNodeComponent *i; // rbx
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v12; // rcx
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v13; // rax
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v14; // rcx
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v15; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TransformNodeComponent::`vftable;
  p_mChildren = &this->mChildren;
  if ( (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **)&this->mChildren.mNode.mNext[-4] != &this->m_SafePointerList.mNode.mNext )
  {
    p_mNext = &this->m_SafePointerList.mNode.mNext;
    do
    {
      mNext = this->mChildren.mNode.mNext;
      mPrev = mNext->mPrev;
      v6 = mNext->mNext;
      mPrev->mNext = v6;
      v6->mPrev = mPrev;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      v7 = mNext - 4;
      mNext[2].mNext = 0i64;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)&mNext[-4]);
      v8 = v7[9];
      v9 = v7[10];
      v10 = v7[11];
      v7[12] = v7[8];
      v7[13] = v8;
      v7[14] = v9;
      v7[15] = v10;
      LODWORD(v7[7].mPrev) = -1;
      ++LODWORD(v7[6].mPrev);
      for ( i = (UFG::TransformNodeComponent *)&v7[5].mNext[-4];
            i != (UFG::TransformNodeComponent *)&v7[1];
            i = (UFG::TransformNodeComponent *)&i->mNext[-4] )
      {
        UFG::TransformNodeComponent::MarkForUpdateHelper((UFG::TransformNodeComponent *)v7, i);
      }
      LODWORD(v7[7].mPrev) = -1;
      ++LODWORD(v7[6].mPrev);
    }
    while ( (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **)&p_mChildren->mNode.mNext[-4] != p_mNext );
  }
  UFG::qList<UFG::TransformNodeComponent,UFG::TransformNodeComponent,1,0>::DeleteNodes(p_mChildren);
  v12 = p_mChildren->mNode.mPrev;
  v13 = p_mChildren->mNode.mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  p_mChildren->mNode.mPrev = &p_mChildren->mNode;
  p_mChildren->mNode.mNext = &p_mChildren->mNode;
  v14 = this->mPrev;
  v15 = this->mNext;
  v14->mNext = v15;
  v15->mPrev = v14;
  this->mPrev = &this->UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent>;
  this->mNext = &this->UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent>;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 100
// RVA: 0x191370
void __fastcall UFG::TransformNodeComponent::SetParent(
        UFG::TransformNodeComponent *this,
        UFG::TransformNodeComponent *new_parent,
        UFG::TransformNodeComponent::eInheritXformType inheritXformType)
{
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *mPrev; // r8
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *mNext; // rax
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v5; // r10
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v6; // rax

  if ( this->mParent != new_parent )
  {
    this->mInheritXformType = inheritXformType;
    mPrev = this->mPrev;
    mNext = this->mNext;
    v5 = &this->UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent>;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mPrev = &this->UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent>;
    this->mNext = &this->UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent>;
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
void __fastcall UFG::TransformNodeComponent::SetParentKeepWorld(
        UFG::TransformNodeComponent *this,
        UFG::TransformNodeComponent *pParent,
        UFG::TransformNodeComponent::eInheritXformType inheritXformType)
{
  UFG::qMatrix44 *p_mWorldTransform; // rdx
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *mPrev; // rcx
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *mNext; // rax
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v8; // rdx
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v9; // rax
  UFG::qMatrix44 d; // [rsp+20h] [rbp-88h] BYREF
  UFG::qMatrix44 result; // [rsp+60h] [rbp-48h] BYREF

  if ( this->mParent != pParent )
  {
    this->mInheritXformType = inheritXformType;
    if ( pParent )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(pParent);
      UFG::qInverseAffine(&d, &pParent->mWorldTransform);
      UFG::TransformNodeComponent::UpdateWorldTransform(this);
      p_mWorldTransform = UFG::qMatrix44::operator*(&this->mWorldTransform, &result, &d);
    }
    else
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(this);
      p_mWorldTransform = &this->mWorldTransform;
    }
    UFG::TransformNodeComponent::SetLocalTransform(this, p_mWorldTransform);
    mPrev = this->mPrev;
    mNext = this->mNext;
    v8 = &this->UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent>;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mPrev = &this->UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent>;
    this->mNext = &this->UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent>;
    if ( pParent )
    {
      v9 = pParent->mChildren.mNode.mPrev;
      v9->mNext = v8;
      v8->mPrev = v9;
      this->mNext = &pParent->mChildren.mNode;
      pParent->mChildren.mNode.mPrev = v8;
    }
    ++this->mChangeID;
    this->mParent = pParent;
    this->mChanged = -1;
  }
}

// File Line: 183
// RVA: 0x191D60
void __fastcall UFG::TransformNodeComponent::UpdateWorldTransform(UFG::TransformNodeComponent *this)
{
  UFG::TransformNodeComponent *mParent; // rdx
  UFG::qVector4 v3; // xmm3
  UFG::qVector4 v4; // xmm2
  UFG::qVector4 v5; // xmm1
  __int64 *v6; // r10
  int v7; // r9d
  int v8; // r8d
  int mChanged; // ecx
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
  UFG::TransformNodeComponent::eInheritXformType mInheritXformType; // ecx
  float v27; // xmm2_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  UFG::qMatrix44 *v30; // rax
  UFG::qVector4 v31; // xmm3
  UFG::qVector4 v32; // xmm2
  UFG::qVector4 v33; // xmm1
  UFG::qMatrix44 b; // [rsp+20h] [rbp-E0h] BYREF
  UFG::qMatrix44 result; // [rsp+60h] [rbp-A0h] BYREF
  __int64 v36[64]; // [rsp+A0h] [rbp-60h] BYREF

  mParent = this->mParent;
  if ( mParent )
  {
    v6 = v36;
    v7 = 0;
    v8 = -1;
    do
    {
      mChanged = mParent->mChanged;
      *v6 = (__int64)mParent;
      mParent = mParent->mParent;
      v10 = mChanged;
      v11 = v7++ & mChanged;
      ++v6;
      v8 = v11 | ~v10 & v8;
    }
    while ( mParent );
    v36[v7] = 0i64;
    v12 = v36[v8 + 1];
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
      v16 = v36[v8--];
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
      v21 = v36[i];
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
    mInheritXformType = this->mInheritXformType;
    if ( mInheritXformType )
    {
      if ( mInheritXformType == eInheritXform_Translation )
      {
        v27 = b.v3.x + this->mLocalTransform.v3.x;
        v28 = b.v3.y + this->mLocalTransform.v3.y;
        v29 = b.v3.z + this->mLocalTransform.v3.z;
        this->mWorldTransform.v3.w = 1.0;
        this->mWorldTransform.v3.x = v27;
        this->mWorldTransform.v3.y = v28;
        this->mWorldTransform.v3.z = v29;
      }
    }
    else
    {
      v30 = UFG::qMatrix44::operator*(&this->mLocalTransform, &result, &b);
      v31 = v30->v1;
      v32 = v30->v2;
      v33 = v30->v3;
      this->mWorldTransform.v0 = v30->v0;
      this->mWorldTransform.v1 = v31;
      this->mWorldTransform.v2 = v32;
      this->mWorldTransform.v3 = v33;
    }
    this->mChanged = 0;
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
void __fastcall UFG::TransformNodeComponent::MarkForUpdateHelper(
        UFG::TransformNodeComponent *this,
        UFG::TransformNodeComponent *node)
{
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *mNext; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **p_mNext; // rdi
  UFG::TransformNodeComponent *v4; // rbx

  mNext = node->mChildren.mNode.mNext;
  ++node->mChangeID;
  p_mNext = &node->m_SafePointerList.mNode.mNext;
  v4 = (UFG::TransformNodeComponent *)&mNext[-4];
  node->mChanged = -1;
  if ( v4 != (UFG::TransformNodeComponent *)&node->m_SafePointerList.mNode.mNext )
  {
    do
    {
      UFG::TransformNodeComponent::MarkForUpdateHelper(this, v4);
      v4 = (UFG::TransformNodeComponent *)&v4->mNext[-4];
    }
    while ( v4 != (UFG::TransformNodeComponent *)p_mNext );
  }
}

// File Line: 299
// RVA: 0x191250
void __fastcall UFG::TransformNodeComponent::SetLocalTransform(UFG::TransformNodeComponent *this, UFG::qMatrix44 *m)
{
  UFG::qVector4 v2; // xmm3
  UFG::qVector4 v3; // xmm2
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **p_mNext; // rsi
  UFG::qVector4 v6; // xmm1
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *mNext; // rbx
  UFG::TransformNodeComponent *v8; // rbx

  v2 = m->v1;
  v3 = m->v2;
  p_mNext = &this->m_SafePointerList.mNode.mNext;
  v6 = m->v3;
  this->mLocalTransform.v0 = m->v0;
  this->mLocalTransform.v1 = v2;
  this->mLocalTransform.v2 = v3;
  this->mLocalTransform.v3 = v6;
  mNext = this->mChildren.mNode.mNext;
  ++this->mChangeID;
  this->mChanged = -1;
  v8 = (UFG::TransformNodeComponent *)&mNext[-4];
  if ( v8 != (UFG::TransformNodeComponent *)&this->m_SafePointerList.mNode.mNext )
  {
    do
    {
      UFG::TransformNodeComponent::MarkForUpdateHelper(this, v8);
      v8 = (UFG::TransformNodeComponent *)&v8->mNext[-4];
    }
    while ( v8 != (UFG::TransformNodeComponent *)p_mNext );
  }
}

// File Line: 309
// RVA: 0x1912E0
void __fastcall UFG::TransformNodeComponent::SetLocalTranslation(UFG::TransformNodeComponent *this, UFG::qVector3 *pos)
{
  float x; // eax
  float y; // xmm0_4
  float z; // xmm1_4
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **p_mNext; // rsi
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *mNext; // rbx
  UFG::TransformNodeComponent *v8; // rbx

  x = pos->x;
  y = pos->y;
  z = pos->z;
  this->mLocalTransform.v3.w = 1.0;
  this->mLocalTransform.v3.x = x;
  p_mNext = &this->m_SafePointerList.mNode.mNext;
  this->mLocalTransform.v3.y = y;
  this->mLocalTransform.v3.z = z;
  mNext = this->mChildren.mNode.mNext;
  ++this->mChangeID;
  v8 = (UFG::TransformNodeComponent *)&mNext[-4];
  this->mChanged = -1;
  if ( v8 != (UFG::TransformNodeComponent *)&this->m_SafePointerList.mNode.mNext )
  {
    do
    {
      UFG::TransformNodeComponent::MarkForUpdateHelper(this, v8);
      v8 = (UFG::TransformNodeComponent *)&v8->mNext[-4];
    }
    while ( v8 != (UFG::TransformNodeComponent *)p_mNext );
  }
}

// File Line: 319
// RVA: 0x1914B0
void __fastcall UFG::TransformNodeComponent::SetWorldTransform(UFG::TransformNodeComponent *this, UFG::qMatrix44 *m)
{
  UFG::TransformNodeComponent *mParent; // rdi
  UFG::qMatrix44 *v3; // rsi
  UFG::TransformNodeComponent *v4; // rbx
  UFG::qMatrix44 *v5; // rax
  UFG::qMatrix44 d; // [rsp+20h] [rbp-88h] BYREF
  UFG::qMatrix44 result; // [rsp+60h] [rbp-48h] BYREF

  mParent = this->mParent;
  v3 = m;
  v4 = this;
  if ( mParent )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(mParent);
    UFG::qInverseAffine(&d, &mParent->mWorldTransform);
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
  UFG::TransformNodeComponent *mParent; // rsi
  float y; // xmm4_4
  float v6; // xmm7_4
  float v7; // xmm3_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm3_4
  float v11; // xmm2_4
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *mNext; // rbx
  UFG::TransformNodeComponent *i; // rbx
  UFG::qMatrix44 d; // [rsp+20h] [rbp-58h] BYREF

  mParent = this->mParent;
  if ( mParent )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(this->mParent);
    UFG::qInverseAffine(&d, &mParent->mWorldTransform);
    y = pos->y;
    v6 = (float)((float)((float)(d.v1.x * y) + (float)(d.v0.x * pos->x)) + (float)(d.v2.x * pos->z)) + d.v3.x;
    v7 = (float)((float)(d.v1.y * y) + (float)(d.v0.y * pos->x)) + (float)(d.v2.y * pos->z);
    v8 = (float)(d.v1.z * y) + (float)(d.v0.z * pos->x);
    v9 = d.v2.z * pos->z;
    this->mLocalTransform.v3.w = 1.0;
    v10 = v7 + d.v3.y;
    this->mLocalTransform.v3.x = v6;
    v11 = (float)(v8 + v9) + d.v3.z;
    this->mLocalTransform.v3.y = v10;
    this->mLocalTransform.v3.z = v11;
    mNext = this->mChildren.mNode.mNext;
    ++this->mChangeID;
    this->mChanged = -1;
    for ( i = (UFG::TransformNodeComponent *)&mNext[-4];
          i != (UFG::TransformNodeComponent *)&this->m_SafePointerList.mNode.mNext;
          i = (UFG::TransformNodeComponent *)&i->mNext[-4] )
    {
      UFG::TransformNodeComponent::MarkForUpdateHelper(this, i);
    }
  }
  else
  {
    UFG::TransformNodeComponent::SetLocalTranslation(this, pos);
  }
}

// File Line: 378
// RVA: 0x191720
void __fastcall UFG::TransformNodeComponent::TeleportEventHandler(
        UFG::TransformNodeComponent *this,
        UFG::Event *this_event)
{
  UFG::TransformNodeComponent *mParent; // rdi
  UFG::TransformNodeComponent *v3; // rbx
  UFG::qMatrix44 *p_m_EventUID; // rsi
  UFG::qMatrix44 *v5; // rdx
  UFG::qMatrix44 *v6; // rax
  UFG::qMatrix44 d; // [rsp+20h] [rbp-88h] BYREF
  UFG::qMatrix44 result; // [rsp+60h] [rbp-48h] BYREF

  mParent = this->mParent;
  v3 = this;
  p_m_EventUID = (UFG::qMatrix44 *)&this_event[1].m_EventUID;
  if ( mParent )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(mParent);
    UFG::qInverseAffine(&d, &mParent->mWorldTransform);
    v6 = UFG::qMatrix44::operator*(p_m_EventUID, &result, &d);
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
void __fastcall UFG::TransformNodeComponent::PropertiesLoadWithMatrix(
        UFG::TransformNodeComponent *this,
        UFG::SceneObjectProperties *pSceneObj,
        UFG::qMatrix44 *pWorldMatrix)
{
  UFG::SceneObjectProperties *m_pSimObject; // rsi
  UFG::qMatrix44 *v5; // rax
  unsigned int *v6; // rax
  unsigned int v7; // edx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  UFG::SceneObjectProperties *Ancestor; // rax
  UFG::SimObject *v10; // rax
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *mPrev; // rcx
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *mNext; // rax
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v13; // rdx
  UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent> *v14; // rax

  m_pSimObject = pSceneObj;
  if ( pWorldMatrix )
  {
    UFG::TransformNodeComponent::SetLocalTransform(this, pWorldMatrix);
  }
  else
  {
    v5 = PropertyUtils::Get<UFG::qMatrix44>(pSceneObj, &qSymbol_XformLocal);
    UFG::TransformNodeComponent::SetLocalTransform(this, v5);
    v6 = PropertyUtils::Get<unsigned long>(m_pSimObject, &qSymbol_XformParent);
    if ( v6 )
      v7 = *v6;
    else
      v7 = 0;
    if ( !m_pSimObject )
    {
      m_pSimObject = (UFG::SceneObjectProperties *)this->m_pSimObject;
      if ( m_pSimObject )
        m_pSimObject = (UFG::SceneObjectProperties *)m_pSimObject->mpOwner.mPrev;
    }
    m_pTransformNodeComponent = 0i64;
    if ( v7 )
    {
      Ancestor = UFG::SceneObjectProperties::GetAncestor(m_pSimObject, v7);
      if ( Ancestor )
      {
        v10 = Ancestor->m_pSimObject;
        if ( v10 )
          m_pTransformNodeComponent = v10->m_pTransformNodeComponent;
      }
    }
    if ( this->mParent != m_pTransformNodeComponent )
    {
      this->mInheritXformType = eInheritXform_Full;
      mPrev = this->mPrev;
      mNext = this->mNext;
      v13 = &this->UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent>;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      this->mPrev = &this->UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent>;
      this->mNext = &this->UFG::qNode<UFG::TransformNodeComponent,UFG::TransformNodeComponent>;
      if ( m_pTransformNodeComponent )
      {
        v14 = m_pTransformNodeComponent->mChildren.mNode.mPrev;
        v14->mNext = v13;
        v13->mPrev = v14;
        this->mNext = &m_pTransformNodeComponent->mChildren.mNode;
        m_pTransformNodeComponent->mChildren.mNode.mPrev = v13;
      }
      ++this->mChangeID;
      this->mParent = m_pTransformNodeComponent;
      this->mChanged = -1;
    }
  }
}

// File Line: 549
// RVA: 0x190E00
void __fastcall UFG::TransformNodeComponent::PropertiesLoad(
        UFG::TransformNodeComponent *this,
        UFG::SceneObjectProperties *pSceneObj)
{
  UFG::TransformNodeComponent::PropertiesLoadWithMatrix(this, pSceneObj, 0i64);
}

