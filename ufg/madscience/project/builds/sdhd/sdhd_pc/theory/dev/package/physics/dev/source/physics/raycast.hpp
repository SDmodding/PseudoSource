// File Line: 55
// RVA: 0x99880
void __fastcall UFG::RayCastData::RayCastData(UFG::RayCastData *this)
{
  this->mInput.m_enableShapeCollectionFilter.m_bool = 0;
  this->mInput.m_filterInfo = 0;
  this->mInput.m_userData = 0i64;
  this->mOutput.m_shapeKeyIndex = 0;
  this->mOutput.m_hitFraction = 1.0;
  this->mOutput.m_extraInfo = -1;
  this->mOutput.m_shapeKeys[0] = -1;
  this->mOutput.m_rootCollidable = 0i64;
  this->mDebugName = 0i64;
  this->mCollisionModelName.mUID = -1;
}

// File Line: 100
// RVA: 0x969F0
void __fastcall UFG::AsyncRayCastData::AsyncRayCastData(UFG::AsyncRayCastData *this)
{
  UFG::CastData *v1; // [rsp+28h] [rbp+10h]

  this->mInput.m_enableShapeCollectionFilter.m_bool = 0;
  this->mInput.m_filterInfo = 0;
  this->mInput.m_userData = 0i64;
  this->mOutput.m_hitFraction = 1.0;
  this->mOutput.m_extraInfo = -1;
  this->mOutput.m_shapeKeyIndex = 0;
  this->mOutput.m_shapeKeys[0] = -1;
  this->mOutput.m_rootCollidable = 0i64;
  this->mDebugName = 0i64;
  this->mCollisionModelName.mUID = -1;
  v1 = (UFG::CastData *)&this->simComponent;
  v1->simComponent.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->simComponent.mPrev;
  v1->simComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->simComponent.mPrev;
  this->simComponent.m_pPointer = 0i64;
  this->callbackUserData = 0i64;
  this->raycastCallback = 0i64;
}

// File Line: 200
// RVA: 0x96A70
void __fastcall UFG::AsyncShapeCasterCollector::AsyncShapeCasterCollector(UFG::AsyncShapeCasterCollector *this)
{
  UFG::qList<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo,1,0> *v1; // [rsp+28h] [rbp+10h]

  this->vfptr = (UFG::ShapeCasterCollectorVtbl *)&UFG::ShapeCasterCollector::`vftable;
  v1 = &this->mHitList;
  v1->mNode.mPrev = &v1->mNode;
  v1->mNode.mNext = &v1->mNode;
  this->mPhantom = 0i64;
  this->mShape = 0i64;
  this->mRadius = 0.0;
  this->vfptr = (UFG::ShapeCasterCollectorVtbl *)&UFG::AsyncShapeCasterCollector::`vftable;
  this->mInput.m_maxExtraPenetration = 0.00000011920929;
  this->mInput.m_startPointTolerance = 0.00000011920929;
}

// File Line: 208
// RVA: 0x9B490
void __fastcall UFG::AsyncShapeCasterCollector::~AsyncShapeCasterCollector(UFG::AsyncShapeCasterCollector *this)
{
  this->vfptr = (UFG::ShapeCasterCollectorVtbl *)&UFG::AsyncShapeCasterCollector::`vftable;
  UFG::ShapeCasterCollector::~ShapeCasterCollector((UFG::ShapeCasterCollector *)&this->vfptr);
}

// File Line: 217
// RVA: 0xA0700
void __fastcall UFG::AsyncShapeCasterCollector::AddHit(UFG::AsyncShapeCasterCollector *this, hkpRootCdPoint *pt, bool oneHitPerRigidBody)
{
  this->mHit = 1;
  this->mOutput.m_contact.m_position = pt->m_contact.m_position;
  this->mOutput.m_contact.m_separatingNormal = pt->m_contact.m_separatingNormal;
  this->mOutput.m_rootCollidableA = pt->m_rootCollidableA;
  this->mOutput.m_shapeKeyA = pt->m_shapeKeyA;
  this->mOutput.m_rootCollidableB = pt->m_rootCollidableB;
  this->mOutput.m_shapeKeyB = pt->m_shapeKeyB;
}

