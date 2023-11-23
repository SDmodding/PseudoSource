// File Line: 37
// RVA: 0x1461380
__int64 dynamic_initializer_for__UFG::AIInterestComponent::s_AIInterestComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::AIInterestComponent::s_AIInterestComponentList__);
}

// File Line: 38
// RVA: 0xFFEC0
__int64 __fastcall UFG::AIInterestComponent::GetTypeSize(UFG::AIInterestComponent *this)
{
  return 432i64;
}

// File Line: 53
// RVA: 0xFA520
void __fastcall UFG::AIInterestComponent::AIInterestComponent(UFG::AIInterestComponent *this, unsigned int name_uid)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  UFG::qNode<UFG::AIInterestComponent,UFG::AIInterestComponent> *mPrev; // rax
  UFG::qVector4 v10; // xmm3
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm2_4

  UFG::SimComponent::SimComponent(this, name_uid);
  this->UFG::StateComponentI<UFG::SimComponent>::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::StateComponentI<UFG::SimComponent>::`vftable{for `UFG::SimComponent};
  this->UFG::StateComponentI<UFG::SimComponent>::UFG::StateInterface::vfptr = (UFG::StateInterfaceVtbl *)&UFG::StateComponentI<UFG::SimComponent>::`vftable{for `UFG::StateInterface};
  this->mAutoActivate = 1;
  this->mAge = 0.0;
  this->mPrev = &this->UFG::qNode<UFG::AIInterestComponent,UFG::AIInterestComponent>;
  this->mNext = &this->UFG::qNode<UFG::AIInterestComponent,UFG::AIInterestComponent>;
  this->UFG::StateComponentI<UFG::SimComponent>::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AIInterestComponent::`vftable{for `UFG::SimComponent};
  this->UFG::StateComponentI<UFG::SimComponent>::UFG::StateInterface::vfptr = (UFG::StateInterfaceVtbl *)&UFG::AIInterestComponent::`vftable{for `UFG::StateInterface};
  this->mGridRequestCount = 0;
  this->mFlags = 144;
  this->mpTransform.mPrev = &this->mpTransform;
  this->mpTransform.mNext = &this->mpTransform;
  this->mpTransform.m_pPointer = 0i64;
  this->mpFieldPrint.mPrev = &this->mpFieldPrint;
  this->mpFieldPrint.mNext = &this->mpFieldPrint;
  this->mpFieldPrint.m_pPointer = 0i64;
  this->msParamTableName = "AvoidableParams";
  *(_QWORD *)&this->mBoundingBox.mMin.x = 0i64;
  *(_QWORD *)&this->mBoundingBox.mMin.z = 0i64;
  *(_QWORD *)&this->mBoundingBox.mMax.y = 0i64;
  this->mBoundingBox.vfptr = (UFG::BoundingVolumeVtbl *)&UFG::SphereVolume::`vftable;
  UFG::qBox::SetRadius(&this->mBoundingBox.UFG::qBox, 1.0);
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mPivotOffset.x = UFG::qVector3::msZero.x;
  this->mPivotOffset.y = y;
  this->mPivotOffset.z = z;
  v5 = UFG::qVector3::msZero.y;
  v6 = UFG::qVector3::msZero.z;
  this->mvAverageVel.x = UFG::qVector3::msZero.x;
  this->mvAverageVel.y = v5;
  this->mvAverageVel.z = v6;
  v7 = UFG::qVector3::msZero.y;
  v8 = UFG::qVector3::msZero.z;
  this->mRotatedPoint.x = UFG::qVector3::msZero.x;
  this->mRotatedPoint.y = v7;
  this->mRotatedPoint.z = v8;
  this->mAttractorParams.Priority = 3.0;
  this->mAttractorParams.SidestepMaxDP = -1.0;
  this->mAttractorParams.FlashlightScoreMax = 0.89999998;
  this->mAttractorParams.FLMaxAngle = 0.35017776;
  this->mAttractorParams.FLMinAngle = 0.0099999998;
  this->mAttractorParams.FLMaxDist = 40.0;
  this->mAttractorParams.Method = 3.0;
  this->mAttractorParams.SidestepMinDP = 0.25;
  this->mAttractorParams.Strength = 4.0;
  *(_QWORD *)&this->mAttractorParams.FLMinDist = 1092616192i64;
  *(_QWORD *)&this->mAttractorParams.Offset.y = 0i64;
  this->mAttractorParams.MinDistToTrackEdge = 3.0;
  this->mAttractorParams.RadiusAdditive = 0.40000001;
  this->mAvoidableParams.Priority = 3.0;
  this->mAvoidableParams.SidestepMaxDP = -1.0;
  this->mAvoidableParams.FlashlightScoreMax = 0.89999998;
  this->mAvoidableParams.FLMaxAngle = 0.35017776;
  this->mAvoidableParams.FLMinAngle = 0.0099999998;
  this->mAvoidableParams.FLMaxDist = 40.0;
  this->mAvoidableParams.Method = 3.0;
  this->mAvoidableParams.SidestepMinDP = 0.25;
  this->mAvoidableParams.Strength = 4.0;
  *(_QWORD *)&this->mAvoidableParams.FLMinDist = 1092616192i64;
  *(_QWORD *)&this->mAvoidableParams.Offset.y = 0i64;
  this->mAvoidableParams.MinDistToTrackEdge = 3.0;
  this->mAvoidableParams.RadiusAdditive = 0.40000001;
  this->mVelocityWindow = 0i64;
  this->mAABBGridIDs[0] = -1;
  UFG::SimComponent::AddType(this, UFG::AIInterestComponent::_AIInterestComponentTypeUID, "AIInterestComponent");
  mPrev = UFG::AIInterestComponent::s_AIInterestComponentList.mNode.mPrev;
  UFG::AIInterestComponent::s_AIInterestComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::AIInterestComponent,UFG::AIInterestComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::AIInterestComponent,UFG::AIInterestComponent> *)&UFG::AIInterestComponent::s_AIInterestComponentList;
  UFG::AIInterestComponent::s_AIInterestComponentList.mNode.mPrev = &this->UFG::qNode<UFG::AIInterestComponent,UFG::AIInterestComponent>;
  v10 = 0i64;
  v10.x = (float)1;
  this->mCachedWorld.v0 = v10;
  this->mCachedWorld.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v10, (__m128)v10, 81);
  this->mCachedWorld.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v10, (__m128)v10, 69);
  this->mCachedWorld.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v10, (__m128)v10, 21);
  this->msParamTableName = "AvoidableParams";
  v11 = UFG::qVector3::msZero.y;
  v12 = UFG::qVector3::msZero.z;
  this->mPivotOffset.x = UFG::qVector3::msZero.x;
  this->mPivotOffset.y = v11;
  this->mPivotOffset.z = v12;
  v13 = UFG::qVector3::msZero.y;
  v14 = UFG::qVector3::msZero.z;
  this->mRotatedPoint.x = UFG::qVector3::msZero.x;
  this->mRotatedPoint.y = v13;
  this->mRotatedPoint.z = v14;
  this->mFlags |= 1u;
}

// File Line: 66
// RVA: 0xFB8D0
void __fastcall UFG::AIInterestComponent::~AIInterestComponent(UFG::AIInterestComponent *this)
{
  UFG::qAverageWindow<UFG::qVector3> *mVelocityWindow; // rdi
  UFG::qNode<UFG::AIInterestComponent,UFG::AIInterestComponent> *v3; // r8
  UFG::qNode<UFG::AIInterestComponent,UFG::AIInterestComponent> *mPrev; // rcx
  UFG::qNode<UFG::AIInterestComponent,UFG::AIInterestComponent> *mNext; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::FFieldPrintComponent> *p_mpFieldPrint; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_mpTransform; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qNode<UFG::AIInterestComponent,UFG::AIInterestComponent> *v16; // rcx
  UFG::qNode<UFG::AIInterestComponent,UFG::AIInterestComponent> *v17; // rax

  this->UFG::StateComponentI<UFG::SimComponent>::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AIInterestComponent::`vftable{for `UFG::SimComponent};
  this->UFG::StateComponentI<UFG::SimComponent>::UFG::StateInterface::vfptr = (UFG::StateInterfaceVtbl *)&UFG::AIInterestComponent::`vftable{for `UFG::StateInterface};
  mVelocityWindow = this->mVelocityWindow;
  if ( mVelocityWindow )
  {
    if ( mVelocityWindow->m_pMemoryPool )
      UFG::qMemoryPool::Free(mVelocityWindow->m_pMemoryPool, mVelocityWindow->m_pBuffer);
    operator delete[](mVelocityWindow);
    this->mVelocityWindow = 0i64;
  }
  if ( this == UFG::AIInterestComponent::s_AIInterestComponentpCurrentIterator )
    UFG::AIInterestComponent::s_AIInterestComponentpCurrentIterator = (UFG::AIInterestComponent *)&this->mPrev[-5];
  v3 = &this->UFG::qNode<UFG::AIInterestComponent,UFG::AIInterestComponent>;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<UFG::AIInterestComponent,UFG::AIInterestComponent>;
  this->mNext = &this->UFG::qNode<UFG::AIInterestComponent,UFG::AIInterestComponent>;
  p_mpFieldPrint = &this->mpFieldPrint;
  if ( this->mpFieldPrint.m_pPointer )
  {
    v7 = p_mpFieldPrint->mPrev;
    v8 = this->mpFieldPrint.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    p_mpFieldPrint->mPrev = p_mpFieldPrint;
    this->mpFieldPrint.mNext = &this->mpFieldPrint;
  }
  this->mpFieldPrint.m_pPointer = 0i64;
  v9 = p_mpFieldPrint->mPrev;
  v10 = this->mpFieldPrint.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  p_mpFieldPrint->mPrev = p_mpFieldPrint;
  this->mpFieldPrint.mNext = &this->mpFieldPrint;
  p_mpTransform = &this->mpTransform;
  if ( this->mpTransform.m_pPointer )
  {
    v12 = p_mpTransform->mPrev;
    v13 = this->mpTransform.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    p_mpTransform->mPrev = p_mpTransform;
    this->mpTransform.mNext = &this->mpTransform;
  }
  this->mpTransform.m_pPointer = 0i64;
  v14 = p_mpTransform->mPrev;
  v15 = this->mpTransform.mNext;
  v14->mNext = v15;
  v15->mPrev = v14;
  p_mpTransform->mPrev = p_mpTransform;
  this->mpTransform.mNext = &this->mpTransform;
  v16 = v3->mPrev;
  v17 = this->mNext;
  v16->mNext = v17;
  v17->mPrev = v16;
  v3->mPrev = v3;
  this->mNext = &this->UFG::qNode<UFG::AIInterestComponent,UFG::AIInterestComponent>;
  this->UFG::StateComponentI<UFG::SimComponent>::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::StateComponentI<UFG::SimComponent>::`vftable{for `UFG::SimComponent};
  this->UFG::StateComponentI<UFG::SimComponent>::UFG::StateInterface::vfptr = (UFG::StateInterfaceVtbl *)&UFG::StateComponentI<UFG::SimComponent>::`vftable{for `UFG::StateInterface};
  if ( (this->m_Flags & 4) != 0 )
  {
    this->m_Flags |= 2u;
    ((void (__fastcall *)(UFG::AIInterestComponent *))this->UFG::StateComponentI<UFG::SimComponent>::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[16].__vecDelDtor)(this);
    this->m_Flags &= ~4u;
  }
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 153
// RVA: 0xFFF10
void __fastcall UFG::AIInterestComponent::Init(
        UFG::AIInterestComponent *this,
        UFG::TransformNodeComponent *pNode,
        UFG::qVector3 *vOffset,
        float fRadius,
        const char *sParamsName)
{
  __m128 v5; // xmm2
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_mpTransform; // rdx
  float y; // xmm1_4
  float v12; // xmm1_4
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::TransformNodeComponent *m_pPointer; // rbx
  float v17; // xmm2_4
  float v18; // xmm6_4
  float v19; // xmm1_4
  float v20; // xmm4_4
  float v21; // xmm4_4
  float v22; // xmm6_4
  float v23; // xmm5_4
  float v24; // xmm0_4
  float v25; // xmm2_4
  float z; // xmm1_4
  float x; // xmm0_4
  float v28; // xmm3_4
  float v29; // xmm1_4
  float v30; // xmm3_4
  float v31; // xmm1_4
  float v32; // xmm0_4

  v5 = 0i64;
  p_mpTransform = &this->mpTransform;
  v5.m128_f32[0] = (float)1;
  this->mCachedWorld.v0 = (UFG::qVector4)v5;
  this->mCachedWorld.v1 = (UFG::qVector4)_mm_shuffle_ps(v5, v5, 81);
  this->mCachedWorld.v2 = (UFG::qVector4)_mm_shuffle_ps(v5, v5, 69);
  this->mCachedWorld.v3 = (UFG::qVector4)_mm_shuffle_ps(v5, v5, 21);
  this->msParamTableName = sParamsName;
  y = UFG::qVector3::msZero.y;
  v5.m128_i32[0] = LODWORD(UFG::qVector3::msZero.z);
  this->mPivotOffset.x = UFG::qVector3::msZero.x;
  this->mPivotOffset.y = y;
  LODWORD(this->mPivotOffset.z) = v5.m128_i32[0];
  v12 = UFG::qVector3::msZero.y;
  v5.m128_i32[0] = LODWORD(UFG::qVector3::msZero.z);
  this->mRotatedPoint.x = UFG::qVector3::msZero.x;
  this->mRotatedPoint.y = v12;
  LODWORD(this->mRotatedPoint.z) = v5.m128_i32[0];
  this->mFlags |= 1u;
  if ( this->mpTransform.m_pPointer )
  {
    mPrev = p_mpTransform->mPrev;
    mNext = p_mpTransform->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpTransform->mPrev = p_mpTransform;
    p_mpTransform->mNext = p_mpTransform;
  }
  p_mpTransform->m_pPointer = pNode;
  if ( pNode )
  {
    v15 = pNode->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
    v15->mNext = p_mpTransform;
    p_mpTransform->mPrev = v15;
    p_mpTransform->mNext = &pNode->m_SafePointerList.mNode;
    pNode->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_mpTransform;
  }
  m_pPointer = (UFG::TransformNodeComponent *)this->mpTransform.m_pPointer;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pPointer);
  v17 = (float)(vOffset->x * m_pPointer->mWorldTransform.v0.y) + (float)(vOffset->y * m_pPointer->mWorldTransform.v1.y);
  v18 = (float)(vOffset->x * m_pPointer->mWorldTransform.v0.z) + (float)(vOffset->y * m_pPointer->mWorldTransform.v1.z);
  v19 = vOffset->z * m_pPointer->mWorldTransform.v2.y;
  v20 = vOffset->z * m_pPointer->mWorldTransform.v2.z;
  this->mPivotOffset.x = (float)((float)(vOffset->y * m_pPointer->mWorldTransform.v1.x)
                               + (float)(vOffset->x * m_pPointer->mWorldTransform.v0.x))
                       + (float)(vOffset->z * m_pPointer->mWorldTransform.v2.x);
  this->mPivotOffset.y = v17 + v19;
  this->mPivotOffset.z = v18 + v20;
  UFG::TransformNodeComponent::UpdateWorldTransform(pNode);
  v21 = (float)((float)(pNode->mWorldTransform.v1.y + pNode->mWorldTransform.v0.y) + pNode->mWorldTransform.v2.y)
      * fRadius;
  v22 = (float)((float)(pNode->mWorldTransform.v1.z + pNode->mWorldTransform.v0.z) + pNode->mWorldTransform.v2.z)
      * fRadius;
  v23 = (float)((float)(pNode->mWorldTransform.v1.x + pNode->mWorldTransform.v0.x) + pNode->mWorldTransform.v2.x)
      * fRadius;
  v24 = this->mBoundingBox.mMax.x - this->mBoundingBox.mMin.x;
  v25 = (float)(this->mBoundingBox.mMax.z - this->mBoundingBox.mMin.z) * 0.5;
  this->mBoundingBox.mMax.y = (float)(this->mBoundingBox.mMax.y - this->mBoundingBox.mMin.y) * 0.5;
  this->mBoundingBox.mMax.z = v25;
  this->mBoundingBox.mMax.x = v24 * 0.5;
  z = UFG::qVector3::msZero.z;
  x = UFG::qVector3::msZero.x;
  v28 = UFG::qVector3::msZero.y;
  this->mBoundingBox.mMin.x = UFG::qVector3::msZero.x;
  this->mBoundingBox.mMin.z = z;
  this->mBoundingBox.mMin.y = v28;
  v29 = z - this->mBoundingBox.mMax.z;
  v30 = v28 - this->mBoundingBox.mMax.y;
  this->mBoundingBox.mMin.x = x - this->mBoundingBox.mMax.x;
  this->mBoundingBox.mMin.z = v29;
  this->mBoundingBox.mMin.y = v30;
  v31 = UFG::qVector3::msZero.z + this->mBoundingBox.mMax.z;
  v32 = UFG::qVector3::msZero.x + this->mBoundingBox.mMax.x;
  this->mBoundingBox.mMax.y = UFG::qVector3::msZero.y + this->mBoundingBox.mMax.y;
  this->mBoundingBox.mMax.z = v31;
  this->mBoundingBox.mMax.x = v32;
  if ( v21 <= v22 )
    v21 = v22;
  if ( v23 <= v21 )
    v23 = v21;
  UFG::qBox::SetRadius(&this->mBoundingBox.UFG::qBox, v23);
  this->mRotatedPoint.x = fRadius;
  this->mRotatedPoint.y = fRadius;
  this->mRotatedPoint.z = fRadius;
}

// File Line: 175
// RVA: 0x100880
void __fastcall UFG::AIInterestComponent::OnAttach(UFG::AIInterestComponent *this, UFG::SimObject *object)
{
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::FFieldPrintComponent> *p_mpFieldPrint; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *p_mNode; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_mpTransform; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax

  m_pTransformNodeComponent = 0i64;
  if ( object )
    ComponentOfType = UFG::SimObject::GetComponentOfType(object, UFG::FFieldPrintComponent::_TypeUID);
  else
    ComponentOfType = 0i64;
  p_mpFieldPrint = &this->mpFieldPrint;
  if ( this->mpFieldPrint.m_pPointer )
  {
    mPrev = p_mpFieldPrint->mPrev;
    mNext = this->mpFieldPrint.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpFieldPrint->mPrev = p_mpFieldPrint;
    this->mpFieldPrint.mNext = &this->mpFieldPrint;
  }
  this->mpFieldPrint.m_pPointer = ComponentOfType;
  if ( ComponentOfType )
  {
    p_mNode = &ComponentOfType->m_SafePointerList.mNode;
    v10 = ComponentOfType->m_SafePointerList.mNode.mPrev;
    v10->mNext = p_mpFieldPrint;
    p_mpFieldPrint->mPrev = v10;
    this->mpFieldPrint.mNext = p_mNode;
    p_mNode->mPrev = p_mpFieldPrint;
  }
  if ( !this->mpTransform.m_pPointer )
  {
    if ( object )
      m_pTransformNodeComponent = object->m_pTransformNodeComponent;
    p_mpTransform = &this->mpTransform;
    if ( this->mpTransform.m_pPointer )
    {
      v12 = p_mpTransform->mPrev;
      v13 = this->mpTransform.mNext;
      v12->mNext = v13;
      v13->mPrev = v12;
      p_mpTransform->mPrev = p_mpTransform;
      this->mpTransform.mNext = &this->mpTransform;
    }
    this->mpTransform.m_pPointer = m_pTransformNodeComponent;
    if ( m_pTransformNodeComponent )
    {
      v14 = m_pTransformNodeComponent->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
      v14->mNext = p_mpTransform;
      p_mpTransform->mPrev = v14;
      this->mpTransform.mNext = &m_pTransformNodeComponent->m_SafePointerList.mNode;
      m_pTransformNodeComponent->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_mpTransform;
    }
  }
}

// File Line: 189
// RVA: 0x1011B0
void __fastcall UFG::AIInterestComponent::OnDetach(UFG::AIInterestComponent *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_mpTransform; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::FFieldPrintComponent> *p_mpFieldPrint; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax

  p_mpTransform = &this->mpTransform;
  if ( this->mpTransform.m_pPointer )
  {
    mPrev = p_mpTransform->mPrev;
    mNext = this->mpTransform.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpTransform->mPrev = p_mpTransform;
    this->mpTransform.mNext = &this->mpTransform;
  }
  p_mpFieldPrint = &this->mpFieldPrint;
  this->mpTransform.m_pPointer = 0i64;
  if ( this->mpFieldPrint.m_pPointer )
  {
    v5 = p_mpFieldPrint->mPrev;
    v6 = p_mpFieldPrint->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    p_mpFieldPrint->mPrev = p_mpFieldPrint;
    p_mpFieldPrint->mNext = p_mpFieldPrint;
  }
  p_mpFieldPrint->m_pPointer = 0i64;
}

// File Line: 248
// RVA: 0x101270
void __fastcall UFG::AIInterestComponent::OnReset(UFG::AIInterestComponent *this)
{
  __m128 v1; // xmm2
  float y; // xmm1_4

  v1 = 0i64;
  this->mFlags &= 0xFFF5u;
  v1.m128_f32[0] = (float)1;
  this->mCachedWorld.v0 = (UFG::qVector4)v1;
  this->mCachedWorld.v1 = (UFG::qVector4)_mm_shuffle_ps(v1, v1, 81);
  this->mCachedWorld.v2 = (UFG::qVector4)_mm_shuffle_ps(v1, v1, 69);
  this->mCachedWorld.v3 = (UFG::qVector4)_mm_shuffle_ps(v1, v1, 21);
  y = UFG::qVector3::msZero.y;
  v1.m128_i32[0] = LODWORD(UFG::qVector3::msZero.z);
  this->mRotatedPoint.x = UFG::qVector3::msZero.x;
  this->mRotatedPoint.y = y;
  LODWORD(this->mRotatedPoint.z) = v1.m128_i32[0];
}

// File Line: 268
// RVA: 0x101450
void __fastcall UFG::AIInterestComponent::OnUpdate(UFG::AIInterestComponent *this, float fDeltaT)
{
  unsigned __int16 mFlags; // cx
  UFG::SimComponent *v5; // rbx
  UFG::qVector4 v6; // xmm2
  float v7; // xmm6_4
  UFG::qVector4 v8; // xmm1
  UFG::qVector4 m_BoundComponentHandles; // xmm3
  float *v10; // rax
  __m128 y_low; // xmm0
  float x; // xmm7_4
  float y; // xmm8_4
  float z; // xmm9_4
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
  UFG::SimComponent *m_pPointer; // rbx
  float v26; // xmm1_4
  UFG::qAverageWindow<UFG::qVector3> *mVelocityWindow; // rcx
  float v28; // xmm0_4
  UFG::qAverageWindow<UFG::qVector3> *v29; // rcx
  float m_RunningSumTime; // xmm2_4
  float v31; // xmm1_4
  float v32; // xmm0_4
  float v33; // xmm0_4
  float v34; // xmm1_4
  UFG::qVector3 result; // [rsp+20h] [rbp-B8h] BYREF
  char v36[16]; // [rsp+30h] [rbp-A8h] BYREF

  mFlags = this->mFlags;
  if ( (mFlags & 4) == 0 && (mFlags & 2) != 0
    || (v5 = this->mpTransform.m_pPointer) == 0i64
    || this == (UFG::AIInterestComponent *)-168i64 )
  {
    this->mFlags = mFlags & 0xFFF7;
  }
  else
  {
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v5);
    v6 = *(UFG::qVector4 *)&v5[2].m_Flags;
    v7 = 0.0;
    v8 = *(UFG::qVector4 *)&v5[2].m_SafePointerList.mNode.mNext;
    m_BoundComponentHandles = (UFG::qVector4)v5[2].m_BoundComponentHandles;
    this->mCachedWorld.v0 = *(UFG::qVector4 *)&v5[2].vfptr;
    this->mCachedWorld.v1 = v8;
    this->mCachedWorld.v2 = v6;
    this->mCachedWorld.v3 = m_BoundComponentHandles;
    UFG::AIInterestComponent::GetCenter(this, &result, 0.0);
    v10 = (float *)((__int64 (__fastcall *)(UFG::SphereVolume *, char *))this->mBoundingBox.vfptr->GetCenter)(
                     &this->mBoundingBox,
                     v36);
    y_low = (__m128)LODWORD(this->mBoundingBox.mMax.y);
    v8.x = this->mBoundingBox.mMax.x - this->mBoundingBox.mMin.x;
    x = result.x;
    y = result.y;
    z = result.z;
    y_low.m128_f32[0] = (float)((float)(y_low.m128_f32[0] - this->mBoundingBox.mMin.y)
                              * (float)(y_low.m128_f32[0] - this->mBoundingBox.mMin.y))
                      + (float)(v8.x * v8.x);
    v6.x = _mm_sqrt_ps(y_low).m128_f32[0] * 0.5;
    v15 = (float)((float)((float)(this->mCachedWorld.v1.x + this->mCachedWorld.v0.x) + this->mCachedWorld.v2.x) * v6.x)
        + (float)(this->mCachedWorld.v3.x * 0.0);
    v16 = (float)((float)((float)(this->mCachedWorld.v1.y + this->mCachedWorld.v0.y) + this->mCachedWorld.v2.y) * v6.x)
        + (float)(this->mCachedWorld.v3.y * 0.0);
    v17 = (float)((float)((float)(this->mCachedWorld.v1.z + this->mCachedWorld.v0.z) + this->mCachedWorld.v2.z) * v6.x)
        + (float)(this->mCachedWorld.v3.z * 0.0);
    if ( (float)((float)((float)((float)(result.x - *v10) * (float)(result.x - *v10))
                       + (float)((float)(result.y - v10[1]) * (float)(result.y - v10[1])))
               + (float)((float)(result.z - v10[2]) * (float)(result.z - v10[2]))) < 0.5
      && (float)((float)((float)((float)(v16 - this->mRotatedPoint.y) * (float)(v16 - this->mRotatedPoint.y))
                       + (float)((float)(v15 - this->mRotatedPoint.x) * (float)(v15 - this->mRotatedPoint.x)))
               + (float)((float)(v17 - this->mRotatedPoint.z) * (float)(v17 - this->mRotatedPoint.z))) < 0.5
      && (v18 = this->mFlags, (v18 & 2) != 0) )
    {
      this->mFlags = v18 & 0xFFF7;
    }
    else
    {
      this->mRotatedPoint.x = v15;
      this->mRotatedPoint.y = v16;
      this->mRotatedPoint.z = v17;
      this->mFlags |= 8u;
      v19 = (float)(this->mBoundingBox.mMax.y - this->mBoundingBox.mMin.y) * 0.5;
      v20 = (float)(this->mBoundingBox.mMax.z - this->mBoundingBox.mMin.z) * 0.5;
      this->mBoundingBox.mMax.x = (float)(this->mBoundingBox.mMax.x - this->mBoundingBox.mMin.x) * 0.5;
      this->mBoundingBox.mMax.y = v19;
      this->mBoundingBox.mMax.z = v20;
      this->mBoundingBox.mMin.x = x;
      this->mBoundingBox.mMin.y = y;
      this->mBoundingBox.mMin.z = z;
      v21 = y - this->mBoundingBox.mMax.y;
      v22 = z - this->mBoundingBox.mMax.z;
      this->mBoundingBox.mMin.x = x - this->mBoundingBox.mMax.x;
      this->mBoundingBox.mMin.y = v21;
      this->mBoundingBox.mMin.z = v22;
      v23 = y + this->mBoundingBox.mMax.y;
      v24 = z + this->mBoundingBox.mMax.z;
      this->mBoundingBox.mMax.x = x + this->mBoundingBox.mMax.x;
      this->mBoundingBox.mMax.y = v23;
      this->mBoundingBox.mMax.z = v24;
    }
    m_pPointer = this->mpTransform.m_pPointer;
    if ( this->mVelocityWindow )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pPointer);
      v26 = *((float *)&m_pPointer[4].vfptr + 1);
      mVelocityWindow = this->mVelocityWindow;
      result.x = *(float *)&m_pPointer[4].vfptr;
      v28 = *(float *)&m_pPointer[4].m_SafePointerList.mNode.mPrev;
      result.y = v26;
      result.z = v28;
      UFG::qAverageWindow<UFG::qVector3>::AddValue(mVelocityWindow, &result, fDeltaT);
      v29 = this->mVelocityWindow;
      if ( v29->m_StartIndex != v29->m_EndIndex )
      {
        m_RunningSumTime = v29->m_RunningSumTime;
        if ( m_RunningSumTime > 0.0 )
        {
          v32 = (float)(1.0 / m_RunningSumTime) * v29->m_RunningSum.z;
          v7 = (float)(1.0 / m_RunningSumTime) * v29->m_RunningSum.x;
          v31 = (float)(1.0 / m_RunningSumTime) * v29->m_RunningSum.y;
          goto LABEL_16;
        }
        v7 = FLOAT_3_4028235e38;
      }
      v31 = v7;
      v32 = v7;
LABEL_16:
      this->mvAverageVel.x = v7;
      this->mvAverageVel.y = v31;
      this->mvAverageVel.z = v32;
      this->mFlags |= 2u;
      return;
    }
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pPointer);
    v33 = *((float *)&m_pPointer[4].vfptr + 1);
    v34 = *(float *)&m_pPointer[4].m_SafePointerList.mNode.mPrev;
    this->mvAverageVel.x = *(float *)&m_pPointer[4].vfptr;
    this->mvAverageVel.y = v33;
    this->mvAverageVel.z = v34;
    this->mFlags |= 2u;
  }
}

// File Line: 405
// RVA: 0xFD5E0
UFG::qVector3 *__fastcall UFG::AIInterestComponent::GetCenter(
        UFG::AIInterestComponent *this,
        UFG::qVector3 *result,
        float t)
{
  float x; // xmm7_4
  float y; // xmm0_4
  float v5; // xmm6_4
  float z; // xmm1_4
  float v7; // xmm5_4
  UFG::qVector3 *v8; // rax
  float v9; // xmm7_4
  float v10; // xmm1_4
  float v11; // xmm7_4
  float v12; // xmm5_4
  float v13; // xmm7_4

  if ( (this->mFlags & 0x100) != 0 )
  {
    x = this->mAttractorParams.Offset.x;
    y = this->mAttractorParams.Offset.y;
    v5 = (float)((float)(y * this->mCachedWorld.v1.x) + (float)(x * this->mCachedWorld.v0.x))
       + (float)(this->mAttractorParams.Offset.z * this->mCachedWorld.v2.x);
    z = this->mAttractorParams.Offset.z;
  }
  else
  {
    x = this->mAvoidableParams.Offset.x;
    y = this->mAvoidableParams.Offset.y;
    v5 = (float)((float)(y * this->mCachedWorld.v1.x) + (float)(x * this->mCachedWorld.v0.x))
       + (float)(this->mAvoidableParams.Offset.z * this->mCachedWorld.v2.x);
    z = this->mAvoidableParams.Offset.z;
  }
  v7 = (float)((float)(x * this->mCachedWorld.v0.z) + (float)(y * this->mCachedWorld.v1.z))
     + (float)(z * this->mCachedWorld.v2.z);
  v8 = result;
  v9 = (float)((float)(x * this->mCachedWorld.v0.y) + (float)(y * this->mCachedWorld.v1.y))
     + (float)(z * this->mCachedWorld.v2.y);
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
  float a; // eax
  Render::DebugDrawContext *Context; // rax
  UFG::qColour colour; // [rsp+30h] [rbp-18h] BYREF

  v3 = (this->mFlags & 0x100) == 0;
  colour = UFG::qColour::Red;
  if ( !v3 )
  {
    if ( (this->mFlags & 1) != 0 )
    {
      colour.r = UFG::qColour::Green.r;
      colour.g = UFG::qColour::Green.g;
      colour.b = UFG::qColour::Green.b;
      a = UFG::qColour::Green.a;
    }
    else
    {
      colour.r = UFG::qColour::ForestGreen.r;
      colour.g = UFG::qColour::ForestGreen.g;
      colour.b = UFG::qColour::ForestGreen.b;
      a = UFG::qColour::ForestGreen.a;
    }
    goto LABEL_7;
  }
  if ( (this->mFlags & 1) == 0 )
  {
    colour.r = UFG::qColour::Maroon.r;
    colour.g = UFG::qColour::Maroon.g;
    colour.b = UFG::qColour::Maroon.b;
    a = UFG::qColour::Maroon.a;
LABEL_7:
    colour.a = a;
  }
  Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
  Render::DebugDrawContext::DrawAABB(
    Context,
    &this->mBoundingBox.mMin,
    &this->mBoundingBox.mMax,
    &colour,
    &UFG::qMatrix44::msIdentity,
    0i64);
}

