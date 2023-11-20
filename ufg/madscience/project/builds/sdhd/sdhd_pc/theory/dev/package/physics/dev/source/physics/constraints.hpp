// File Line: 45
// RVA: 0x98400
void __fastcall UFG::ConstraintDef::ConstraintDef(UFG::ConstraintDef *this, MemImageLoadFlag f)
{
  UFG::ConstraintDef *v2; // rbx
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v3; // rdi
  unsigned __int64 v4; // rax
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v5; // rax
  const char *v6; // rax
  UFG::qString *v7; // rax
  char *v8; // rax
  UFG::qBaseNodeRB *v9; // rdx
  UFG::qString result; // [rsp+28h] [rbp-60h]
  UFG::qString v11; // [rsp+50h] [rbp-38h]
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v12; // [rsp+A0h] [rbp+18h]

  v2 = this;
  v3 = (UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *)&this->mBaseNode;
  v4 = this->mBaseNode.mUID;
  v3->mBaseNode.mParent = &v3->mBaseNode;
  v3->mBaseNode.mChildren[0] = &v3->mBaseNode;
  v3->mBaseNode.mChildren[1] = &v3->mBaseNode;
  v3->mBaseNode.mNeighbours[0] = &v3->mBaseNode;
  v3->mBaseNode.mNeighbours[1] = &v3->mBaseNode;
  v3->mBaseNode.mUID = v4;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable';
  v5 = &this->mHandles;
  v12 = &this->mHandles;
  v5->mNode.mPrev = &v5->mNode;
  v5->mNode.mNext = &v5->mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::ConstraintDef,UFG::qReflectObject>::`vftable';
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::ConstraintDef::`vftable';
  _((AMD_HD3D *)this->mAudioEffect.mUID);
  v6 = UFG::qReflectObject::GetName((UFG::qReflectObject *)&v2->vfptr);
  UFG::qString::qString(&v11, v6);
  UFG::qString::Trim(v7, &result);
  UFG::qString::~qString(&v11);
  v2->mName = (UFG::qSymbol)UFG::qSymbol::create_from_string((UFG::qSymbol *)&v12, result.mData)->mUID;
  UFG::qString::~qString(&result);
  v8 = UFG::qMalloc(0x28ui64, UFG::gGlobalNewName, 0i64);
  v9 = (UFG::qBaseNodeRB *)v8;
  v12 = (UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)v8;
  if ( v8 )
  {
    *(_QWORD *)v8 = 0i64;
    *((_QWORD *)v8 + 1) = 0i64;
    *((_QWORD *)v8 + 2) = 0i64;
  }
  else
  {
    v9 = 0i64;
  }
  v9->mUID = v2->mName.mUID;
  v9[1].mParent = (UFG::qBaseNodeRB *)v3->mBaseNode.mUID;
  UFG::qBaseTreeRB::Add(&UFG::ConstraintDef::sConstraintLookup.mTree, v9);
}

// File Line: 65
// RVA: 0x9BF60
void __fastcall UFG::ConstraintDef::~ConstraintDef(UFG::ConstraintDef *this)
{
  UFG::ConstraintDef *v1; // rbx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v2; // rcx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v3; // rax
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v4; // [rsp+40h] [rbp+8h]

  v1 = this;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::ConstraintDef::`vftable';
  _((AMD_HD3D *)this->mAudioEffect.mUID);
  v1->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable';
  v4 = &v1->mHandles;
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0>::DeleteNodes(&v1->mHandles);
  v2 = v1->mHandles.mNode.mPrev;
  v3 = v1->mHandles.mNode.mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v4->mNode.mPrev = &v4->mNode;
  v4->mNode.mNext = &v4->mNode;
}

// File Line: 227
// RVA: 0x98530
void __fastcall UFG::ConstraintDefRagdoll::ConstraintDefRagdoll(UFG::ConstraintDefRagdoll *this, MemImageLoadFlag f)
{
  UFG::ConstraintDefRagdoll *v2; // rbx
  __m128 v3; // xmm2
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  __m128 v8; // xmm2
  float v9; // xmm0_4
  float v10; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm0_4

  v2 = this;
  UFG::ConstraintDef::ConstraintDef((UFG::ConstraintDef *)&this->vfptr, f);
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UFG::ConstraintDefRagdoll,UFG::ConstraintDef>::`vftable';
  v2->vfptr = (UFG::qReflectObjectVtbl *)&UFG::ConstraintDefRagdoll::`vftable';
  v3 = (__m128)LODWORD(v2->mTwistAxis.x);
  v3.m128_f32[0] = (float)((float)(v3.m128_f32[0] * v3.m128_f32[0]) + (float)(v2->mTwistAxis.y * v2->mTwistAxis.y))
                 + (float)(v2->mTwistAxis.z * v2->mTwistAxis.z);
  LODWORD(v4) = (unsigned __int128)_mm_sqrt_ps(v3);
  if ( v4 > 0.0 )
  {
    v5 = 1.0 / v4;
    v6 = (float)(1.0 / v4) * v2->mTwistAxis.z;
    v7 = (float)(1.0 / v4) * v2->mTwistAxis.y;
    v2->mTwistAxis.x = v5 * v2->mTwistAxis.x;
    v2->mTwistAxis.y = v7;
    v2->mTwistAxis.z = v6;
  }
  v8 = (__m128)LODWORD(v2->mPlaneAxis.x);
  v8.m128_f32[0] = (float)((float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(v2->mPlaneAxis.y * v2->mPlaneAxis.y))
                 + (float)(v2->mPlaneAxis.z * v2->mPlaneAxis.z);
  LODWORD(v9) = (unsigned __int128)_mm_sqrt_ps(v8);
  if ( v9 > 0.0 )
  {
    v10 = 1.0 / v9;
    v11 = (float)(1.0 / v9) * v2->mPlaneAxis.z;
    v12 = (float)(1.0 / v9) * v2->mPlaneAxis.y;
    v2->mPlaneAxis.x = v10 * v2->mPlaneAxis.x;
    v2->mPlaneAxis.y = v12;
    v2->mPlaneAxis.z = v11;
  }
}

