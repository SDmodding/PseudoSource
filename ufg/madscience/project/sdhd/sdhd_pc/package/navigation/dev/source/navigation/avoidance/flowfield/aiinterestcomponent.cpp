// File Line: 37
// RVA: 0x1461380
__int64 dynamic_initializer_for__UFG::AIInterestComponent::s_AIInterestComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::AIInterestComponent::s_AIInterestComponentList__);
}

// File Line: 38
// RVA: 0xFFEC0
signed __int64 __fastcall UFG::AIInterestComponent::GetTypeSize(UFG::AIInterestComponent *this)
{
  return 432i64;
}

// File Line: 53
// RVA: 0xFA520
void __fastcall UFG::AIInterestComponent::AIInterestComponent(UFG::AIInterestComponent *this, unsigned int name_uid)
{
  UFG::AIInterestComponent *v2; // rdi
  UFG::qNode<UFG::AIInterestComponent,UFG::AIInterestComponent> *v3; // rbx
  _QWORD *v4; // rcx
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  UFG::qNode<UFG::AIInterestComponent,UFG::AIInterestComponent> *v11; // rax
  __m128 v12; // xmm3
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v17; // [rsp+60h] [rbp+18h]
  UFG::qSafePointer<UFG::SimComponent,UFG::FFieldPrintComponent> *v18; // [rsp+60h] [rbp+18h]

  v2 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::StateComponentI<UFG::SimComponent>::`vftable{for `UFG::SimComponent};
  v2->vfptr = (UFG::StateInterfaceVtbl *)&UFG::StateComponentI<UFG::SimComponent>::`vftable{for `UFG::StateInterface};
  v2->mAutoActivate = 1;
  v2->mAge = 0.0;
  v3 = (UFG::qNode<UFG::AIInterestComponent,UFG::AIInterestComponent> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AIInterestComponent::`vftable{for `UFG::SimComponent};
  v2->vfptr = (UFG::StateInterfaceVtbl *)&UFG::AIInterestComponent::`vftable{for `UFG::StateInterface};
  v2->mGridRequestCount = 0;
  v2->mFlags = 144;
  v17 = &v2->mpTransform;
  v17->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
  v17->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
  v2->mpTransform.m_pPointer = 0i64;
  v18 = &v2->mpFieldPrint;
  v18->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v18->mPrev;
  v18->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v18->mPrev;
  v2->mpFieldPrint.m_pPointer = 0i64;
  v2->msParamTableName = "AvoidableParams";
  v4 = (_QWORD *)&v2->mBoundingBox.mMin.x;
  *v4 = 0i64;
  v4[1] = 0i64;
  v4[2] = 0i64;
  v2->mBoundingBox.vfptr = (UFG::BoundingVolumeVtbl *)&UFG::SphereVolume::`vftable;
  UFG::qBox::SetRadius((UFG::qBox *)&v2->mBoundingBox.mMin, 1.0);
  v5 = UFG::qVector3::msZero.y;
  v6 = UFG::qVector3::msZero.z;
  v2->mPivotOffset.x = UFG::qVector3::msZero.x;
  v2->mPivotOffset.y = v5;
  v2->mPivotOffset.z = v6;
  v7 = UFG::qVector3::msZero.y;
  v8 = UFG::qVector3::msZero.z;
  v2->mvAverageVel.x = UFG::qVector3::msZero.x;
  v2->mvAverageVel.y = v7;
  v2->mvAverageVel.z = v8;
  v9 = UFG::qVector3::msZero.y;
  v10 = UFG::qVector3::msZero.z;
  v2->mRotatedPoint.x = UFG::qVector3::msZero.x;
  v2->mRotatedPoint.y = v9;
  v2->mRotatedPoint.z = v10;
  v2->mAttractorParams.Priority = 3.0;
  v2->mAttractorParams.SidestepMaxDP = -1.0;
  v2->mAttractorParams.FlashlightScoreMax = 0.89999998;
  v2->mAttractorParams.FLMaxAngle = 0.35017776;
  v2->mAttractorParams.FLMinAngle = 0.0099999998;
  v2->mAttractorParams.FLMaxDist = 40.0;
  v2->mAttractorParams.Method = 3.0;
  v2->mAttractorParams.SidestepMinDP = 0.25;
  v2->mAttractorParams.Strength = 4.0;
  *(_QWORD *)&v2->mAttractorParams.FLMinDist = 1092616192i64;
  *(_QWORD *)&v2->mAttractorParams.Offset.y = 0i64;
  v2->mAttractorParams.MinDistToTrackEdge = 3.0;
  v2->mAttractorParams.RadiusAdditive = 0.40000001;
  v2->mAvoidableParams.Priority = 3.0;
  v2->mAvoidableParams.SidestepMaxDP = -1.0;
  v2->mAvoidableParams.FlashlightScoreMax = 0.89999998;
  v2->mAvoidableParams.FLMaxAngle = 0.35017776;
  v2->mAvoidableParams.FLMinAngle = 0.0099999998;
  v2->mAvoidableParams.FLMaxDist = 40.0;
  v2->mAvoidableParams.Method = 3.0;
  v2->mAvoidableParams.SidestepMinDP = 0.25;
  v2->mAvoidableParams.Strength = 4.0;
  *(_QWORD *)&v2->mAvoidableParams.FLMinDist = 1092616192i64;
  *(_QWORD *)&v2->mAvoidableParams.Offset.y = 0i64;
  v2->mAvoidableParams.MinDistToTrackEdge = 3.0;
  v2->mAvoidableParams.RadiusAdditive = 0.40000001;
  v2->mVelocityWindow = 0i64;
  v2->mAABBGridIDs[0] = -1;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::AIInterestComponent::_AIInterestComponentTypeUID,
    "AIInterestComponent");
  v11 = UFG::AIInterestComponent::s_AIInterestComponentList.mNode.mPrev;
  UFG::AIInterestComponent::s_AIInterestComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::AIInterestComponent,UFG::AIInterestComponent> *)&v2->mPrev;
  v3->mPrev = v11;
  v2->mNext = (UFG::qNode<UFG::AIInterestComponent,UFG::AIInterestComponent> *)&UFG::AIInterestComponent::s_AIInterestComponentList;
  UFG::AIInterestComponent::s_AIInterestComponentList.mNode.mPrev = (UFG::qNode<UFG::AIInterestComponent,UFG::AIInterestComponent> *)&v2->mPrev;
  v12 = 0i64;
  v12.m128_f32[0] = (float)1;
  v2->mCachedWorld.v0 = (UFG::qVector4)v12;
  v2->mCachedWorld.v1 = (UFG::qVector4)_mm_shuffle_ps(v12, v12, 81);
  v2->mCachedWorld.v2 = (UFG::qVector4)_mm_shuffle_ps(v12, v12, 69);
  v2->mCachedWorld.v3 = (UFG::qVector4)_mm_shuffle_ps(v12, v12, 21);
  v2->msParamTableName = "AvoidableParams";
  v13 = UFG::qVector3::msZero.y;
  v14 = UFG::qVector3::msZero.z;
  v2->mPivotOffset.x = UFG::qVector3::msZero.x;
  v2->mPivotOffset.y = v13;
  v2->mPivotOffset.z = v14;
  v15 = UFG::qVector3::msZero.y;
  v16 = UFG::qVector3::msZero.z;
  v2->mRotatedPoint.x = UFG::qVector3::msZero.x;
  v2->mRotatedPoint.y = v15;
  v2->mRotatedPoint.z = v16;
  v2->mFlags |= 1u;
}

// File Line: 66
// RVA: 0xFB8D0
void __fastcall UFG::AIInterestComponent::~AIInterestComponent(UFG::AIInterestComponent *this)
{
  UFG::AIInterestComponent *v1; // rbx
  UFG::qAverageWindow<UFG::qVector3> *v2; // rdi
  UFG::qNode<UFG::AIInterestComponent,UFG::AIInterestComponent> *v3; // r8
  UFG::qNode<UFG::AIInterestComponent,UFG::AIInterestComponent> *v4; // rcx
  UFG::qNode<UFG::AIInterestComponent,UFG::AIInterestComponent> *v5; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::FFieldPrintComponent> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v11; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qNode<UFG::AIInterestComponent,UFG::AIInterestComponent> *v16; // rcx
  UFG::qNode<UFG::AIInterestComponent,UFG::AIInterestComponent> *v17; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AIInterestComponent::`vftable{for `UFG::SimComponent};
  this->vfptr = (UFG::StateInterfaceVtbl *)&UFG::AIInterestComponent::`vftable{for `UFG::StateInterface};
  v2 = this->mVelocityWindow;
  if ( v2 )
  {
    if ( v2->m_pMemoryPool )
      UFG::qMemoryPool::Free(v2->m_pMemoryPool, v2->m_pBuffer);
    operator delete[](v2);
    v1->mVelocityWindow = 0i64;
  }
  if ( v1 == UFG::AIInterestComponent::s_AIInterestComponentpCurrentIterator )
    UFG::AIInterestComponent::s_AIInterestComponentpCurrentIterator = (UFG::AIInterestComponent *)&v1->mPrev[-5];
  v3 = (UFG::qNode<UFG::AIInterestComponent,UFG::AIInterestComponent> *)&v1->mPrev;
  v4 = v1->mPrev;
  v5 = v1->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v3->mPrev = v3;
  v3->mNext = v3;
  v6 = &v1->mpFieldPrint;
  if ( v1->mpFieldPrint.m_pPointer )
  {
    v7 = v6->mPrev;
    v8 = v1->mpFieldPrint.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    v1->mpFieldPrint.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mpFieldPrint.mPrev;
  }
  v1->mpFieldPrint.m_pPointer = 0i64;
  v9 = v6->mPrev;
  v10 = v1->mpFieldPrint.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v1->mpFieldPrint.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mpFieldPrint.mPrev;
  v11 = &v1->mpTransform;
  if ( v1->mpTransform.m_pPointer )
  {
    v12 = v11->mPrev;
    v13 = v1->mpTransform.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mPrev;
    v1->mpTransform.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mpTransform.mPrev;
  }
  v1->mpTransform.m_pPointer = 0i64;
  v14 = v11->mPrev;
  v15 = v1->mpTransform.mNext;
  v14->mNext = v15;
  v15->mPrev = v14;
  v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  v1->mpTransform.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mpTransform.mPrev;
  v16 = v3->mPrev;
  v17 = v1->mNext;
  v16->mNext = v17;
  v17->mPrev = v16;
  v3->mPrev = v3;
  v1->mNext = (UFG::qNode<UFG::AIInterestComponent,UFG::AIInterestComponent> *)&v1->mPrev;
  v1->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::StateComponentI<UFG::SimComponent>::`vftable{for `UFG::SimComponent};
  v1->vfptr = (UFG::StateInterfaceVtbl *)&UFG::StateComponentI<UFG::SimComponent>::`vftable{for `UFG::StateInterface};
  if ( (LOBYTE(v1->m_Flags) >> 2) & 1 )
  {
    v1->m_Flags |= 2u;
    ((void (__fastcall *)(UFG::AIInterestComponent *))v1->vfptr[16].__vecDelDtor)(v1);
    v1->m_Flags &= 0xFFFBu;
  }
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 153
// RVA: 0xFFF10
void __fastcall UFG::AIInterestComponent::Init(UFG::AIInterestComponent *this, UFG::TransformNodeComponent *pNode, UFG::qVector3 *vOffset, float fRadius, const char *sParamsName)
{
  __m128 v5; // xmm2
  UFG::TransformNodeComponent *v6; // rsi
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v7; // rdx
  UFG::qVector3 *v8; // rbp
  float v9; // xmm7_4
  UFG::AIInterestComponent *v10; // rdi
  float v11; // xmm1_4
  float v12; // xmm1_4
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax
  float *v16; // rbx
  float v17; // xmm2_4
  float v18; // xmm6_4
  float v19; // xmm1_4
  float v20; // xmm4_4
  UFG::qBox *v21; // rcx
  float v22; // xmm4_4
  float v23; // xmm6_4
  float v24; // xmm5_4
  float v25; // xmm0_4
  float v26; // xmm2_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm3_4
  float v30; // xmm1_4
  float v31; // xmm3_4
  float v32; // xmm1_4
  float v33; // xmm0_4

  v5 = 0i64;
  v6 = pNode;
  v7 = &this->mpTransform;
  v5.m128_f32[0] = (float)1;
  v8 = vOffset;
  v9 = fRadius;
  v10 = this;
  this->mCachedWorld.v0 = (UFG::qVector4)v5;
  this->mCachedWorld.v1 = (UFG::qVector4)_mm_shuffle_ps(v5, v5, 81);
  this->mCachedWorld.v2 = (UFG::qVector4)_mm_shuffle_ps(v5, v5, 69);
  this->mCachedWorld.v3 = (UFG::qVector4)_mm_shuffle_ps(v5, v5, 21);
  this->msParamTableName = sParamsName;
  v11 = UFG::qVector3::msZero.y;
  v5.m128_i32[0] = LODWORD(UFG::qVector3::msZero.z);
  this->mPivotOffset.x = UFG::qVector3::msZero.x;
  this->mPivotOffset.y = v11;
  LODWORD(this->mPivotOffset.z) = v5.m128_i32[0];
  v12 = UFG::qVector3::msZero.y;
  v5.m128_i32[0] = LODWORD(UFG::qVector3::msZero.z);
  this->mRotatedPoint.x = UFG::qVector3::msZero.x;
  this->mRotatedPoint.y = v12;
  LODWORD(this->mRotatedPoint.z) = v5.m128_i32[0];
  this->mFlags |= 1u;
  if ( this->mpTransform.m_pPointer )
  {
    v13 = v7->mPrev;
    v14 = v7->mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v7->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  }
  v7->m_pPointer = (UFG::SimComponent *)&v6->vfptr;
  if ( v6 )
  {
    v15 = v6->m_SafePointerList.mNode.mPrev;
    v15->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v7->mPrev = v15;
    v7->mNext = &v6->m_SafePointerList.mNode;
    v6->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  }
  v16 = (float *)v10->mpTransform.m_pPointer;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v10->mpTransform.m_pPointer);
  v17 = (float)(v8->x * v16[33]) + (float)(v8->y * v16[37]);
  v18 = (float)(v8->x * v16[34]) + (float)(v8->y * v16[38]);
  v19 = v8->z * v16[41];
  v20 = v8->z * v16[42];
  v10->mPivotOffset.x = (float)((float)(v8->y * v16[36]) + (float)(v8->x * v16[32])) + (float)(v8->z * v16[40]);
  v10->mPivotOffset.y = v17 + v19;
  v10->mPivotOffset.z = v18 + v20;
  UFG::TransformNodeComponent::UpdateWorldTransform(v6);
  v21 = (UFG::qBox *)&v10->mBoundingBox.mMin;
  v22 = (float)((float)(v6->mWorldTransform.v1.y + v6->mWorldTransform.v0.y) + v6->mWorldTransform.v2.y) * fRadius;
  v23 = (float)((float)(v6->mWorldTransform.v1.z + v6->mWorldTransform.v0.z) + v6->mWorldTransform.v2.z) * fRadius;
  v24 = (float)((float)(v6->mWorldTransform.v1.x + v6->mWorldTransform.v0.x) + v6->mWorldTransform.v2.x) * fRadius;
  v25 = v10->mBoundingBox.mMax.x - v10->mBoundingBox.mMin.x;
  v26 = (float)(v10->mBoundingBox.mMax.z - v10->mBoundingBox.mMin.z) * 0.5;
  v21->mMax.y = (float)(v10->mBoundingBox.mMax.y - v10->mBoundingBox.mMin.y) * 0.5;
  v21->mMax.z = v26;
  v21->mMax.x = v25 * 0.5;
  v27 = UFG::qVector3::msZero.z;
  v28 = UFG::qVector3::msZero.x;
  v29 = UFG::qVector3::msZero.y;
  v21->mMin.x = UFG::qVector3::msZero.x;
  v21->mMin.z = v27;
  v21->mMin.y = v29;
  v30 = v27 - v10->mBoundingBox.mMax.z;
  v31 = v29 - v10->mBoundingBox.mMax.y;
  v21->mMin.x = v28 - v10->mBoundingBox.mMax.x;
  v21->mMin.z = v30;
  v21->mMin.y = v31;
  v32 = UFG::qVector3::msZero.z + v10->mBoundingBox.mMax.z;
  v33 = UFG::qVector3::msZero.x + v10->mBoundingBox.mMax.x;
  v21->mMax.y = UFG::qVector3::msZero.y + v10->mBoundingBox.mMax.y;
  v21->mMax.z = v32;
  v21->mMax.x = v33;
  if ( v22 <= v23 )
    v22 = v23;
  if ( v24 <= v22 )
    v24 = v22;
  UFG::qBox::SetRadius(v21, v24);
  v10->mRotatedPoint.x = v9;
  v10->mRotatedPoint.y = v9;
  v10->mRotatedPoint.z = v9;
}

// File Line: 175
// RVA: 0x100880
void __fastcall UFG::AIInterestComponent::OnAttach(UFG::AIInterestComponent *this, UFG::SimObject *object)
{
  UFG::TransformNodeComponent *v2; // rbx
  UFG::SimObject *v3; // rdi
  UFG::AIInterestComponent *v4; // rsi
  UFG::SimComponent *v5; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::FFieldPrintComponent> *v6; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qList<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList,1,0> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v11; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax

  v2 = 0i64;
  v3 = object;
  v4 = this;
  if ( object )
    v5 = UFG::SimObject::GetComponentOfType(object, UFG::FFieldPrintComponent::_TypeUID);
  else
    v5 = 0i64;
  v6 = &v4->mpFieldPrint;
  if ( v4->mpFieldPrint.m_pPointer )
  {
    v7 = v6->mPrev;
    v8 = v4->mpFieldPrint.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    v4->mpFieldPrint.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mpFieldPrint.mPrev;
  }
  v4->mpFieldPrint.m_pPointer = v5;
  if ( v5 )
  {
    v9 = &v5->m_SafePointerList;
    v10 = v5->m_SafePointerList.mNode.mPrev;
    v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    v6->mPrev = v10;
    v4->mpFieldPrint.mNext = &v9->mNode;
    v9->mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  }
  if ( !v4->mpTransform.m_pPointer )
  {
    if ( v3 )
      v2 = v3->m_pTransformNodeComponent;
    v11 = &v4->mpTransform;
    if ( v4->mpTransform.m_pPointer )
    {
      v12 = v11->mPrev;
      v13 = v4->mpTransform.mNext;
      v12->mNext = v13;
      v13->mPrev = v12;
      v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mPrev;
      v4->mpTransform.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mpTransform.mPrev;
    }
    v4->mpTransform.m_pPointer = (UFG::SimComponent *)&v2->vfptr;
    if ( v2 )
    {
      v14 = v2->m_SafePointerList.mNode.mPrev;
      v14->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mPrev;
      v11->mPrev = v14;
      v4->mpTransform.mNext = &v2->m_SafePointerList.mNode;
      v2->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v11->mPrev;
    }
  }
}

// File Line: 189
// RVA: 0x1011B0
void __fastcall UFG::AIInterestComponent::OnDetach(UFG::AIInterestComponent *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v1; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::FFieldPrintComponent> *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax

  v1 = &this->mpTransform;
  if ( this->mpTransform.m_pPointer )
  {
    v2 = v1->mPrev;
    v3 = this->mpTransform.mNext;
    v2->mNext = v3;
    v3->mPrev = v2;
    v1->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mPrev;
    this->mpTransform.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->mpTransform.mPrev;
  }
  v4 = &this->mpFieldPrint;
  this->mpTransform.m_pPointer = 0i64;
  if ( this->mpFieldPrint.m_pPointer )
  {
    v5 = v4->mPrev;
    v6 = v4->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  }
  v4->m_pPointer = 0i64;
}

// File Line: 248
// RVA: 0x101270
void __fastcall UFG::AIInterestComponent::OnReset(UFG::AIInterestComponent *this)
{
  __m128 v1; // xmm2
  float v2; // xmm1_4

  v1 = 0i64;
  this->mFlags &= 0xFFF5u;
  v1.m128_f32[0] = (float)1;
  this->mCachedWorld.v0 = (UFG::qVector4)v1;
  this->mCachedWorld.v1 = (UFG::qVector4)_mm_shuffle_ps(v1, v1, 81);
  this->mCachedWorld.v2 = (UFG::qVector4)_mm_shuffle_ps(v1, v1, 69);
  this->mCachedWorld.v3 = (UFG::qVector4)_mm_shuffle_ps(v1, v1, 21);
  v2 = UFG::qVector3::msZero.y;
  v1.m128_i32[0] = LODWORD(UFG::qVector3::msZero.z);
  this->mRotatedPoint.x = UFG::qVector3::msZero.x;
  this->mRotatedPoint.y = v2;
  LODWORD(this->mRotatedPoint.z) = v1.m128_i32[0];
}

// File Line: 268
// RVA: 0x101450
void __fastcall UFG::AIInterestComponent::OnUpdate(UFG::AIInterestComponent *this, float fDeltaT)
{
  UFG::AIInterestComponent *v2; // rdi
  unsigned __int16 v3; // cx
  float v4; // xmm11_4
  UFG::SimComponent *v5; // rbx
  UFG::qVector4 v6; // xmm2
  float v7; // xmm6_4
  UFG::qVector4 v8; // xmm1
  UFG::qVector4 v9; // xmm3
  float *v10; // rax
  __m128 v11; // xmm0
  float v12; // xmm7_4
  float v13; // xmm8_4
  float v14; // xmm9_4
  float v15; // xmm12_4
  float v16; // xmm13_4
  float v17; // xmm14_4
  unsigned __int16 v18; // cx
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm1_4
  float v23; // xmm8_4
  float v24; // xmm9_4
  float *v25; // rbx
  UFG::TransformNodeComponent *v26; // rcx
  float v27; // xmm1_4
  UFG::qAverageWindow<UFG::qVector3> *v28; // rcx
  float v29; // xmm0_4
  UFG::qAverageWindow<UFG::qVector3> *v30; // rcx
  float v31; // xmm2_4
  float v32; // xmm1_4
  float v33; // xmm0_4
  float v34; // xmm0_4
  float v35; // xmm1_4
  UFG::qVector3 result; // [rsp+20h] [rbp-B8h]
  char v37; // [rsp+30h] [rbp-A8h]

  v2 = this;
  v3 = this->mFlags;
  v4 = fDeltaT;
  if ( (((unsigned __int8)v3 >> 2) & 1 || ~((unsigned __int8)v3 >> 1) & 1)
    && (v5 = v2->mpTransform.m_pPointer) != 0i64
    && v2 != (UFG::AIInterestComponent *)-168i64 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v5);
    v6 = *(UFG::qVector4 *)&v5[2].m_Flags;
    v7 = 0.0;
    v8 = *(UFG::qVector4 *)&v5[2].m_SafePointerList.mNode.mNext;
    v9 = (UFG::qVector4)v5[2].m_BoundComponentHandles;
    v2->mCachedWorld.v0 = *(UFG::qVector4 *)&v5[2].vfptr;
    v2->mCachedWorld.v1 = v8;
    v2->mCachedWorld.v2 = v6;
    v2->mCachedWorld.v3 = v9;
    UFG::AIInterestComponent::GetCenter(v2, &result, 0.0);
    v10 = (float *)((__int64 (__fastcall *)(UFG::SphereVolume *, char *))v2->mBoundingBox.vfptr->GetCenter)(
                     &v2->mBoundingBox,
                     &v37);
    v11 = (__m128)LODWORD(v2->mBoundingBox.mMax.y);
    v8.x = v2->mBoundingBox.mMax.x - v2->mBoundingBox.mMin.x;
    v12 = result.x;
    v13 = result.y;
    v14 = result.z;
    v11.m128_f32[0] = (float)((float)(v11.m128_f32[0] - v2->mBoundingBox.mMin.y)
                            * (float)(v11.m128_f32[0] - v2->mBoundingBox.mMin.y))
                    + (float)(v8.x * v8.x);
    v6.x = COERCE_FLOAT(_mm_sqrt_ps(v11)) * 0.5;
    v15 = (float)((float)((float)(v2->mCachedWorld.v1.x + v2->mCachedWorld.v0.x) + v2->mCachedWorld.v2.x) * v6.x)
        + (float)(v2->mCachedWorld.v3.x * 0.0);
    v16 = (float)((float)((float)(v2->mCachedWorld.v1.y + v2->mCachedWorld.v0.y) + v2->mCachedWorld.v2.y) * v6.x)
        + (float)(v2->mCachedWorld.v3.y * 0.0);
    v17 = (float)((float)((float)(v2->mCachedWorld.v1.z + v2->mCachedWorld.v0.z) + v2->mCachedWorld.v2.z) * v6.x)
        + (float)(v2->mCachedWorld.v3.z * 0.0);
    if ( (float)((float)((float)((float)(result.x - *v10) * (float)(result.x - *v10))
                       + (float)((float)(result.y - v10[1]) * (float)(result.y - v10[1])))
               + (float)((float)(result.z - v10[2]) * (float)(result.z - v10[2]))) < 0.5
      && (float)((float)((float)((float)(v16 - v2->mRotatedPoint.y) * (float)(v16 - v2->mRotatedPoint.y))
                       + (float)((float)(v15 - v2->mRotatedPoint.x) * (float)(v15 - v2->mRotatedPoint.x)))
               + (float)((float)(v17 - v2->mRotatedPoint.z) * (float)(v17 - v2->mRotatedPoint.z))) < 0.5
      && (v18 = v2->mFlags, ((unsigned __int8)v18 >> 1) & 1) )
    {
      v2->mFlags = v18 & 0xFFF7;
    }
    else
    {
      v2->mRotatedPoint.x = v15;
      v2->mRotatedPoint.y = v16;
      v2->mRotatedPoint.z = v17;
      v2->mFlags |= 8u;
      v19 = (float)(v2->mBoundingBox.mMax.y - v2->mBoundingBox.mMin.y) * 0.5;
      v20 = (float)(v2->mBoundingBox.mMax.z - v2->mBoundingBox.mMin.z) * 0.5;
      v2->mBoundingBox.mMax.x = (float)(v2->mBoundingBox.mMax.x - v2->mBoundingBox.mMin.x) * 0.5;
      v2->mBoundingBox.mMax.y = v19;
      v2->mBoundingBox.mMax.z = v20;
      v2->mBoundingBox.mMin.x = v12;
      v2->mBoundingBox.mMin.y = v13;
      v2->mBoundingBox.mMin.z = v14;
      v21 = v13 - v2->mBoundingBox.mMax.y;
      v22 = v14 - v2->mBoundingBox.mMax.z;
      v2->mBoundingBox.mMin.x = v12 - v2->mBoundingBox.mMax.x;
      v2->mBoundingBox.mMin.y = v21;
      v2->mBoundingBox.mMin.z = v22;
      v23 = v13 + v2->mBoundingBox.mMax.y;
      v24 = v14 + v2->mBoundingBox.mMax.z;
      v2->mBoundingBox.mMax.x = v12 + v2->mBoundingBox.mMax.x;
      v2->mBoundingBox.mMax.y = v23;
      v2->mBoundingBox.mMax.z = v24;
    }
    v25 = (float *)v2->mpTransform.m_pPointer;
    v26 = (UFG::TransformNodeComponent *)v2->mpTransform.m_pPointer;
    if ( v2->mVelocityWindow )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(v26);
      v27 = v25[65];
      v28 = v2->mVelocityWindow;
      result.x = v25[64];
      v29 = v25[66];
      result.y = v27;
      result.z = v29;
      UFG::qAverageWindow<UFG::qVector3>::AddValue(v28, &result, v4);
      v30 = v2->mVelocityWindow;
      if ( v30->m_StartIndex != v30->m_EndIndex )
      {
        v31 = v30->m_RunningSumTime;
        if ( v31 > 0.0 )
        {
          v33 = (float)(1.0 / v31) * v30->m_RunningSum.z;
          v7 = (float)(1.0 / v31) * v30->m_RunningSum.x;
          v32 = (float)(1.0 / v31) * v30->m_RunningSum.y;
          goto LABEL_16;
        }
        v7 = FLOAT_3_4028235e38;
      }
      v32 = v7;
      v33 = v7;
LABEL_16:
      v2->mvAverageVel.x = v7;
      v2->mvAverageVel.y = v32;
      v2->mvAverageVel.z = v33;
      v2->mFlags |= 2u;
      return;
    }
    UFG::TransformNodeComponent::UpdateWorldTransform(v26);
    v34 = v25[65];
    v35 = v25[66];
    v2->mvAverageVel.x = v25[64];
    v2->mvAverageVel.y = v34;
    v2->mvAverageVel.z = v35;
    v2->mFlags |= 2u;
  }
  else
  {
    v2->mFlags = v3 & 0xFFF7;
  }
}

// File Line: 405
// RVA: 0xFD5E0
UFG::qVector3 *__fastcall UFG::AIInterestComponent::GetCenter(UFG::AIInterestComponent *this, UFG::qVector3 *result, float t)
{
  float v3; // xmm7_4
  float v4; // xmm0_4
  float v5; // xmm6_4
  float v6; // xmm1_4
  float v7; // xmm5_4
  UFG::qVector3 *v8; // rax
  float v9; // xmm7_4
  float v10; // xmm1_4
  float v11; // xmm7_4
  float v12; // xmm5_4
  float v13; // xmm7_4

  if ( this->mFlags & 0x100 )
  {
    v3 = this->mAttractorParams.Offset.x;
    v4 = this->mAttractorParams.Offset.y;
    v5 = (float)((float)(this->mAttractorParams.Offset.y * this->mCachedWorld.v1.x)
               + (float)(this->mAttractorParams.Offset.x * this->mCachedWorld.v0.x))
       + (float)(this->mAttractorParams.Offset.z * this->mCachedWorld.v2.x);
    v6 = this->mAttractorParams.Offset.z;
  }
  else
  {
    v3 = this->mAvoidableParams.Offset.x;
    v4 = this->mAvoidableParams.Offset.y;
    v5 = (float)((float)(this->mAvoidableParams.Offset.y * this->mCachedWorld.v1.x)
               + (float)(this->mAvoidableParams.Offset.x * this->mCachedWorld.v0.x))
       + (float)(this->mAvoidableParams.Offset.z * this->mCachedWorld.v2.x);
    v6 = this->mAvoidableParams.Offset.z;
  }
  v7 = (float)((float)(v3 * this->mCachedWorld.v0.z) + (float)(v4 * this->mCachedWorld.v1.z))
     + (float)(v6 * this->mCachedWorld.v2.z);
  v8 = result;
  v9 = (float)((float)(v3 * this->mCachedWorld.v0.y) + (float)(v4 * this->mCachedWorld.v1.y))
     + (float)(v6 * this->mCachedWorld.v2.y);
  v10 = t * this->mvAverageVel.y;
  v11 = v9 + this->mPivotOffset.y;
  v12 = (float)((float)(v7 + this->mPivotOffset.z) + this->mCachedWorld.v3.z) + (float)(t * this->mvAverageVel.z);
  result->x = (float)((float)(v5 + this->mPivotOffset.x) + this->mCachedWorld.v3.x) + (float)(t * this->mvAverageVel.x);
  v13 = v11 + this->mCachedWorld.v3.y;
  result->z = v12;
  result->y = v13 + v10;
  return v8;
}

// File Line: 477
// RVA: 0xFCF10
void __fastcall UFG::AIInterestComponent::DebugDraw(UFG::AIInterestComponent *this, float fDeltaT, Render::View *pView)
{
  bool v3; // zf
  UFG::AIInterestComponent *v4; // rbx
  float v5; // eax
  Render::DebugDrawContext *v6; // rax
  UFG::qColour colour; // [rsp+30h] [rbp-18h]

  v3 = (this->mFlags & 0x100) == 0;
  v4 = this;
  colour = UFG::qColour::Red;
  if ( !v3 )
  {
    if ( this->mFlags & 1 )
    {
      colour.r = UFG::qColour::Green.r;
      colour.g = UFG::qColour::Green.g;
      colour.b = UFG::qColour::Green.b;
      v5 = UFG::qColour::Green.a;
    }
    else
    {
      colour.r = UFG::qColour::ForestGreen.r;
      colour.g = UFG::qColour::ForestGreen.g;
      colour.b = UFG::qColour::ForestGreen.b;
      v5 = UFG::qColour::ForestGreen.a;
    }
    goto LABEL_7;
  }
  if ( !(this->mFlags & 1) )
  {
    colour.r = UFG::qColour::Maroon.r;
    colour.g = UFG::qColour::Maroon.g;
    colour.b = UFG::qColour::Maroon.b;
    v5 = UFG::qColour::Maroon.a;
LABEL_7:
    colour.a = v5;
  }
  v6 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
  Render::DebugDrawContext::DrawAABB(
    v6,
    &v4->mBoundingBox.mMin,
    &v4->mBoundingBox.mMax,
    &colour,
    &UFG::qMatrix44::msIdentity,
    0i64);
}

