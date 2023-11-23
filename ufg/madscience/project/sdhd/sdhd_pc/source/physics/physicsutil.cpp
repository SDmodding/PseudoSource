// File Line: 53
// RVA: 0x475B80
void __fastcall UFG::ShearObject(
        UFG::SimObject *pShearable,
        UFG::qVector3 *impulseLS,
        UFG::qVector3 *impulseOffsetLS,
        const bool impulseAtCentreOfMass)
{
  UFG::RigidBody *p_mNext; // rsi
  int v9; // ebp
  UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *v10; // rdx
  unsigned int v11; // ebx
  UFG::CollisionInstanceData *mInstanceData; // r8
  unsigned int mNumParts; // ecx
  UFG::CollisionInstanceData::Part *mParts; // r8
  __int64 v15; // rsi
  hkpRigidBody *v16; // rbx
  float v17; // xmm1_4
  float v18; // xmm2_4
  hkVector4f v19; // [rsp+20h] [rbp-118h] BYREF
  __int64 v20; // [rsp+30h] [rbp-108h]
  hkVector4f v21; // [rsp+40h] [rbp-F8h] BYREF
  hkVector4f v22; // [rsp+50h] [rbp-E8h] BYREF
  hkVector4f b; // [rsp+60h] [rbp-D8h] BYREF
  hkTransformf a; // [rsp+70h] [rbp-C8h] BYREF
  hkpPhysicsSystem bodiesOut; // [rsp+B0h] [rbp-88h] BYREF

  if ( pShearable )
  {
    v20 = -2i64;
    p_mNext = (UFG::RigidBody *)&UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext;
    if ( &UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext != (UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> **)((char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList - 280) )
    {
      v9 = 0;
      while ( 1 )
      {
        v10 = (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)&p_mNext[1].m_SafePointerList.mNode.mPrev[-18].mNext;
        v11 = 0;
        mInstanceData = p_mNext->mInstanceData;
        mNumParts = mInstanceData->mNumParts;
        if ( mNumParts )
          break;
LABEL_8:
        p_mNext = (UFG::RigidBody *)&p_mNext[1].m_SafePointerList.mNode.mPrev[-18].mNext;
        if ( v10 == (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)((char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList
                                                                                      - 280) )
          return;
      }
      mParts = mInstanceData->mParts;
      while ( mParts[v11].mSimObject.m_pPointer != pShearable )
      {
        if ( ++v11 >= mNumParts )
          goto LABEL_8;
      }
      hkpPhysicsSystem::hkpPhysicsSystem(&bodiesOut);
      UFG::Destruction::ForceFracture(UFG::Destruction::mInstance, p_mNext, &bodiesOut, v11);
      if ( bodiesOut.m_rigidBodies.m_size > 0 )
      {
        v15 = 0i64;
        do
        {
          v16 = bodiesOut.m_rigidBodies.m_data[v15];
          a = v16->m_motion.m_motionState.m_transform;
          if ( impulseAtCentreOfMass )
          {
            v17 = v16->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal.m_quad.m128_f32[1]
                + impulseOffsetLS->y;
            v18 = v16->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal.m_quad.m128_f32[2]
                + impulseOffsetLS->z;
            impulseOffsetLS->x = v16->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal.m_quad.m128_f32[0]
                               + impulseOffsetLS->x;
            impulseOffsetLS->y = v17;
            impulseOffsetLS->z = v18;
          }
          v22.m_quad = _mm_unpacklo_ps(
                         _mm_unpacklo_ps((__m128)LODWORD(impulseLS->x), (__m128)LODWORD(impulseLS->z)),
                         _mm_unpacklo_ps((__m128)LODWORD(impulseLS->y), (__m128)0i64));
          b.m_quad = _mm_unpacklo_ps(
                       _mm_unpacklo_ps((__m128)LODWORD(impulseOffsetLS->x), (__m128)LODWORD(impulseOffsetLS->z)),
                       _mm_unpacklo_ps((__m128)LODWORD(impulseOffsetLS->y), (__m128)0i64));
          hkVector4f::setTransformedPos(&v19, &a, &b);
          hkVector4f::setRotatedDir(&v21, &a.m_rotation, &v22);
          hkpEntity::activate(v16);
          ((void (__fastcall *)(hkpMaxSizeMotion *, hkVector4f *, hkVector4f *))v16->m_motion.hkpEntity::vfptr[11].__first_virtual_table_function__)(
            &v16->m_motion,
            &v21,
            &v19);
          ++v9;
          ++v15;
        }
        while ( v9 < bodiesOut.m_rigidBodies.m_size );
      }
      hkpPhysicsSystem::~hkpPhysicsSystem(&bodiesOut);
    }
  }
}

// File Line: 129
// RVA: 0x45C6C0
UFG::Constraint *__fastcall UFG::CreateConstraint_Util(
        hkpRigidBody *havokRigidBody1,
        hkpRigidBody *havokRigidBody2,
        UFG::qVector3 *pivotWorldConstraint)
{
  _QWORD **Value; // rax
  hkpBallSocketChainData *v6; // rax
  __int64 v7; // rbx
  hkpBallSocketChainData *v8; // rax
  hkpBallSocketChainData *v9; // rsi
  _QWORD **v10; // rax
  hkpConstraintChainInstance *v11; // rax
  hkpConstraintChainInstance *v12; // rax
  hkpConstraintChainInstance *v13; // rdi
  UFG::allocator::free_link *v14; // rax
  __int64 v15; // rax
  hkVector4f pivotInB; // [rsp+40h] [rbp-48h] BYREF
  hkVector4f pivotInA; // [rsp+50h] [rbp-38h] BYREF
  UFG::qSymbol result; // [rsp+90h] [rbp+8h] BYREF
  UFG::allocator::free_link *v20; // [rsp+98h] [rbp+10h]
  UFG::qVector3 *_name; // [rsp+A0h] [rbp+18h] BYREF
  UFG::qVector3 **p_name; // [rsp+A8h] [rbp+20h]

  _name = pivotWorldConstraint;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v6 = (hkpBallSocketChainData *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 112i64);
  _name = (UFG::qVector3 *)v6;
  v7 = 0i64;
  if ( v6 )
  {
    hkpBallSocketChainData::hkpBallSocketChainData(v6);
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  v10 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v11 = (hkpConstraintChainInstance *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v10[11] + 8i64))(v10[11], 144i64);
  _name = (UFG::qVector3 *)v11;
  if ( v11 )
  {
    hkpConstraintChainInstance::hkpConstraintChainInstance(v11, v9);
    v13 = v12;
  }
  else
  {
    v13 = 0i64;
  }
  hkpConstraintChainInstance::addEntity(v13, havokRigidBody1);
  pivotInB.m_quad = 0i64;
  pivotInA.m_quad = 0i64;
  hkpBallSocketChainData::addConstraintInfoInBodySpace(v9, &pivotInA, &pivotInB);
  hkpConstraintChainInstance::addEntity(v13, havokRigidBody2);
  hkReferencedObject::removeReference(v9);
  UFG::qSymbol::create_from_string(&result, "CreateConstraint_Util");
  v14 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x60ui64, "Constraint", 0i64, 1u);
  v20 = v14;
  if ( v14 )
  {
    p_name = &_name;
    LODWORD(_name) = result;
    UFG::Constraint::Constraint((UFG::Constraint *)v14, (unsigned int *)&_name);
    v7 = v15;
  }
  *(_QWORD *)(v7 + 40) = v13;
  return (UFG::Constraint *)v7;
}

