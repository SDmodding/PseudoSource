// File Line: 45
// RVA: 0x98400
void __fastcall UFG::ConstraintDef::ConstraintDef(UFG::ConstraintDef *this, MemImageLoadFlag f)
{
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v3; // rdi
  unsigned __int64 mUID; // rax
  const char *Name; // rax
  UFG::qString *v6; // rax
  char *v7; // rax
  UFG::qBaseNodeRB *v8; // rdx
  UFG::qString result; // [rsp+28h] [rbp-60h] BYREF
  UFG::qString v10; // [rsp+50h] [rbp-38h] BYREF
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *p_mHandles; // [rsp+A0h] [rbp+18h] BYREF

  v3 = &this->UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject>;
  mUID = this->mBaseNode.mUID;
  this->mBaseNode.mParent = &this->mBaseNode;
  this->mBaseNode.mChildren[0] = &this->mBaseNode;
  this->mBaseNode.mChildren[1] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[0] = &this->mBaseNode;
  this->mBaseNode.mNeighbours[1] = &this->mBaseNode;
  this->mBaseNode.mUID = mUID;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  p_mHandles = &this->mHandles;
  this->mHandles.mNode.mPrev = &this->mHandles.mNode;
  this->mHandles.mNode.mNext = &this->mHandles.mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::ConstraintDef,UFG::qReflectObject>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::ConstraintDef::`vftable;
  _((AMD_HD3D *)this->mAudioEffect.mUID);
  Name = UFG::qReflectObject::GetName(this);
  UFG::qString::qString(&v10, Name);
  UFG::qString::Trim(v6, &result);
  UFG::qString::~qString(&v10);
  this->mName = (UFG::qSymbol)UFG::qSymbol::create_from_string((UFG::qSymbol *)&p_mHandles, result.mData)->mUID;
  UFG::qString::~qString(&result);
  v7 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
  v8 = (UFG::qBaseNodeRB *)v7;
  p_mHandles = (UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)v7;
  if ( v7 )
  {
    *(_QWORD *)v7 = 0i64;
    *((_QWORD *)v7 + 1) = 0i64;
    *((_QWORD *)v7 + 2) = 0i64;
  }
  else
  {
    v8 = 0i64;
  }
  v8->mUID = this->mName.mUID;
  v8[1].mParent = (UFG::qBaseNodeRB *)v3->mBaseNode.mUID;
  UFG::qBaseTreeRB::Add(&UFG::ConstraintDef::sConstraintLookup.mTree, v8);
}

// File Line: 65
// RVA: 0x9BF60
void __fastcall UFG::ConstraintDef::~ConstraintDef(UFG::ConstraintDef *this)
{
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *mPrev; // rcx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *mNext; // rax

  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::ConstraintDef::`vftable;
  _((AMD_HD3D *)this->mAudioEffect.mUID);
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable;
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0>::DeleteNodes(&this->mHandles);
  mPrev = this->mHandles.mNode.mPrev;
  mNext = this->mHandles.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mHandles.mNode.mPrev = &this->mHandles.mNode;
  this->mHandles.mNode.mNext = &this->mHandles.mNode;
}

// File Line: 227
// RVA: 0x98530
void __fastcall UFG::ConstraintDefRagdoll::ConstraintDefRagdoll(UFG::ConstraintDefRagdoll *this, MemImageLoadFlag f)
{
  __m128 x_low; // xmm2
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  __m128 v8; // xmm2
  float v9; // xmm0_4
  float v10; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm0_4

  UFG::ConstraintDef::ConstraintDef(this, f);
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::ConstraintDefRagdoll,UFG::ConstraintDef>::`vftable;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::ConstraintDefRagdoll::`vftable;
  x_low = (__m128)LODWORD(this->mTwistAxis.x);
  x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0])
                            + (float)(this->mTwistAxis.y * this->mTwistAxis.y))
                    + (float)(this->mTwistAxis.z * this->mTwistAxis.z);
  v4 = _mm_sqrt_ps(x_low).m128_f32[0];
  if ( v4 > 0.0 )
  {
    v5 = 1.0 / v4;
    v6 = (float)(1.0 / v4) * this->mTwistAxis.z;
    v7 = (float)(1.0 / v4) * this->mTwistAxis.y;
    this->mTwistAxis.x = v5 * this->mTwistAxis.x;
    this->mTwistAxis.y = v7;
    this->mTwistAxis.z = v6;
  }
  v8 = (__m128)LODWORD(this->mPlaneAxis.x);
  v8.m128_f32[0] = (float)((float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(this->mPlaneAxis.y * this->mPlaneAxis.y))
                 + (float)(this->mPlaneAxis.z * this->mPlaneAxis.z);
  v9 = _mm_sqrt_ps(v8).m128_f32[0];
  if ( v9 > 0.0 )
  {
    v10 = 1.0 / v9;
    v11 = (float)(1.0 / v9) * this->mPlaneAxis.z;
    v12 = (float)(1.0 / v9) * this->mPlaneAxis.y;
    this->mPlaneAxis.x = v10 * this->mPlaneAxis.x;
    this->mPlaneAxis.y = v12;
    this->mPlaneAxis.z = v11;
  }
}

