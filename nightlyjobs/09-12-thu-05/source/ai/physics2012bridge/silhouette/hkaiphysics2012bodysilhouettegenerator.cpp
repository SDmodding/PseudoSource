// File Line: 17
// RVA: 0xC2F740
void __fastcall hkaiPhysics2012BodySilhouetteGenerator::hkaiPhysics2012BodySilhouetteGenerator(hkaiPhysics2012BodySilhouetteGenerator *this, hkpRigidBody *rb, hkaiPhysics2012WorldListener *listener)
{
  hkaiPhysics2012WorldListener *v3; // rbx
  hkpRigidBody *v4; // rdi
  hkaiPhysics2012BodySilhouetteGenerator *v5; // rsi
  __m128i v6; // xmm1
  hkVector4f translationInOut; // [rsp+20h] [rbp-38h]
  hkVector4f linearVel; // [rsp+30h] [rbp-28h]
  hkQuaternionf rbRotation; // [rsp+40h] [rbp-18h]

  v3 = listener;
  v4 = rb;
  v5 = this;
  hkaiPhysicsBodySilhouetteGeneratorBase::hkaiPhysicsBodySilhouetteGeneratorBase((hkaiPhysicsBodySilhouetteGeneratorBase *)&this->vfptr);
  v5->vfptr = (hkBaseObjectVtbl *)&hkaiPhysics2012BodySilhouetteGenerator::`vftable';
  v5->m_rigidBody.m_pntr = 0i64;
  v5->m_physicsWorldListener = v3;
  v6 = (__m128i)v4->m_motion.m_motionState.m_transform.m_translation;
  _mm_store_si128((__m128i *)&rbRotation, (__m128i)v4->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad);
  _mm_store_si128((__m128i *)&translationInOut, v6);
  hkaiPhysics2012BodySilhouetteGenerator::addWorldShift(v5, &translationInOut);
  _mm_store_si128((__m128i *)&linearVel, (__m128i)v4->m_motion.m_linearVelocity.m_quad);
  hkaiPhysics2012BodySilhouetteGenerator::setRigidBody(v5, v4);
  hkaiPhysicsBodySilhouetteGeneratorBase::updateFromBodyInfo(
    (hkaiPhysicsBodySilhouetteGeneratorBase *)&v5->vfptr,
    &rbRotation,
    &translationInOut,
    &linearVel);
  v5->m_weldTolerance = 0.000001;
}

// File Line: 35
// RVA: 0xC2F800
void __fastcall hkaiPhysics2012BodySilhouetteGenerator::hkaiPhysics2012BodySilhouetteGenerator(hkaiPhysics2012BodySilhouetteGenerator *this, hkFinishLoadedObjectFlag f)
{
  hkaiPhysics2012BodySilhouetteGenerator *v2; // rbx

  v2 = this;
  hkaiPhysicsBodySilhouetteGeneratorBase::hkaiPhysicsBodySilhouetteGeneratorBase(
    (hkaiPhysicsBodySilhouetteGeneratorBase *)&this->vfptr,
    f);
  v2->vfptr = (hkBaseObjectVtbl *)&hkaiPhysics2012BodySilhouetteGenerator::`vftable';
}

// File Line: 39
// RVA: 0xC2F970
void __fastcall hkaiPhysics2012BodySilhouetteGenerator::~hkaiPhysics2012BodySilhouetteGenerator(hkaiPhysics2012BodySilhouetteGenerator *this)
{
  hkaiPhysics2012BodySilhouetteGenerator *v1; // rbx
  hkpRigidBody *v2; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiPhysics2012BodySilhouetteGenerator::`vftable';
  v2 = this->m_rigidBody.m_pntr;
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  v1->m_rigidBody.m_pntr = 0i64;
  hkaiPhysicsBodySilhouetteGeneratorBase::~hkaiPhysicsBodySilhouetteGeneratorBase((hkaiPhysicsBodySilhouetteGeneratorBase *)&v1->vfptr);
}

// File Line: 43
// RVA: 0xC2F830
void __fastcall hkaiPhysics2012BodySilhouetteGenerator::setRigidBody(hkaiPhysics2012BodySilhouetteGenerator *this, hkpRigidBody *rb)
{
  hkpRigidBody *v2; // rbx
  hkaiPhysics2012BodySilhouetteGenerator *v3; // rdi
  hkReferencedObject *v4; // rcx

  v2 = rb;
  v3 = this;
  if ( rb )
    hkReferencedObject::addReference((hkReferencedObject *)&rb->vfptr);
  v4 = (hkReferencedObject *)&v3->m_rigidBody.m_pntr->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v3->m_rigidBody.m_pntr = v2;
  hkaiPhysics2012BodySilhouetteGenerator::setPointCloudFromShape(v3, v2->m_collidable.m_shape);
}

// File Line: 49
// RVA: 0xC2F890
void __fastcall hkaiPhysics2012BodySilhouetteGenerator::setPointCloudFromShape(hkaiPhysics2012BodySilhouetteGenerator *this, hkpShape *shape)
{
  hkaiPhysics2012BodySilhouetteGenerator *v2; // rbx
  hkArray<int,hkContainerHeapAllocator> sizesOut; // [rsp+20h] [rbp-28h]
  hkArray<hkVector4f,hkContainerHeapAllocator> verticesOut; // [rsp+30h] [rbp-18h]

  v2 = this;
  verticesOut.m_data = 0i64;
  verticesOut.m_size = 0;
  verticesOut.m_capacityAndFlags = 2147483648;
  sizesOut.m_data = 0i64;
  sizesOut.m_size = 0;
  sizesOut.m_capacityAndFlags = 2147483648;
  hkaiPhysics2012SilhouetteBuilder::createPointCloudFromShapeRecursive(
    shape,
    &hkQsTransformf_identityStorage,
    &verticesOut,
    &sizesOut);
  hkaiPointCloudSilhouetteGenerator::setLocalPoints(
    (hkaiPointCloudSilhouetteGenerator *)&v2->vfptr,
    (hkArrayBase<hkVector4f> *)&verticesOut.m_data,
    &sizesOut);
  sizesOut.m_size = 0;
  if ( sizesOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      sizesOut.m_data,
      4 * sizesOut.m_capacityAndFlags);
  sizesOut.m_data = 0i64;
  sizesOut.m_capacityAndFlags = 2147483648;
  verticesOut.m_size = 0;
  if ( verticesOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      verticesOut.m_data,
      16 * verticesOut.m_capacityAndFlags);
}

// File Line: 59
// RVA: 0xC2F9C0
void __fastcall hkaiPhysics2012BodySilhouetteGenerator::getBodyRotationAndTranslation(hkaiPhysics2012BodySilhouetteGenerator *this, hkQuaternionf *rotationOut, hkVector4f *translationOut)
{
  hkVector4f *v3; // rbx
  hkVector4f translationInOut; // [rsp+20h] [rbp-18h]

  v3 = translationOut;
  *rotationOut = this->m_rigidBody.m_pntr->m_motion.m_motionState.m_sweptTransform.m_rotation1;
  _mm_store_si128(
    (__m128i *)&translationInOut,
    (__m128i)this->m_rigidBody.m_pntr->m_motion.m_motionState.m_transform.m_translation.m_quad);
  hkaiPhysics2012BodySilhouetteGenerator::addWorldShift(this, &translationInOut);
  *v3 = (hkVector4f)translationInOut.m_quad;
}

// File Line: 67
// RVA: 0xC2FA10
void __fastcall hkaiPhysics2012BodySilhouetteGenerator::getBodyLinearVelocity(hkaiPhysics2012BodySilhouetteGenerator *this, hkVector4f *velocityOut)
{
  *velocityOut = this->m_rigidBody.m_pntr->m_motion.m_linearVelocity;
}

// File Line: 72
// RVA: 0xC2FA50
void __fastcall hkaiPhysics2012BodySilhouetteGenerator::addWorldShift(hkaiPhysics2012BodySilhouetteGenerator *this, hkVector4f *translationInOut)
{
  hkaiPhysics2012WorldListener *v2; // rax

  v2 = this->m_physicsWorldListener;
  if ( v2 )
    translationInOut->m_quad = _mm_add_ps(v2->m_worldShift.m_quad, translationInOut->m_quad);
}

// File Line: 80
// RVA: 0xC2FA30
_BOOL8 __fastcall hkaiPhysics2012BodySilhouetteGenerator::isInWorld(hkaiPhysics2012BodySilhouetteGenerator *this)
{
  return this->m_rigidBody.m_pntr->m_world != 0i64;
}

