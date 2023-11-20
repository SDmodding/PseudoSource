// File Line: 53
// RVA: 0x475B80
void __fastcall UFG::ShearObject(UFG::SimObject *pShearable, UFG::qVector3 *impulseLS, UFG::qVector3 *impulseOffsetLS, const bool impulseAtCentreOfMass)
{
  bool v4; // r14
  UFG::qVector3 *v5; // rdi
  UFG::qVector3 *v6; // r15
  UFG::SimObject *v7; // r10
  UFG::RigidBody *v8; // rsi
  int v9; // ebp
  UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *v10; // rdx
  unsigned int v11; // ebx
  UFG::CollisionInstanceData *v12; // r8
  unsigned int v13; // ecx
  UFG::CollisionInstanceData::Part *v14; // r8
  __int64 v15; // rsi
  hkpRigidBody *v16; // rbx
  float v17; // xmm1_4
  float v18; // xmm2_4
  hkVector4f v19; // [rsp+20h] [rbp-118h]
  __int64 v20; // [rsp+30h] [rbp-108h]
  hkVector4f v21; // [rsp+40h] [rbp-F8h]
  hkVector4f v22; // [rsp+50h] [rbp-E8h]
  hkVector4f b; // [rsp+60h] [rbp-D8h]
  hkTransformf a; // [rsp+70h] [rbp-C8h]
  hkpPhysicsSystem bodiesOut; // [rsp+B0h] [rbp-88h]

  if ( pShearable )
  {
    v20 = -2i64;
    v4 = impulseAtCentreOfMass;
    v5 = impulseOffsetLS;
    v6 = impulseLS;
    v7 = pShearable;
    v8 = (UFG::RigidBody *)&UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext;
    if ( &UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext != (UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> **)((char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList - 280) )
    {
      v9 = 0;
      while ( 1 )
      {
        v10 = (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)&v8[1].m_SafePointerList.mNode.mPrev[-18].mNext;
        v11 = 0;
        v12 = v8->mInstanceData;
        v13 = v12->mNumParts;
        if ( v13 )
          break;
LABEL_8:
        v8 = (UFG::RigidBody *)&v8[1].m_SafePointerList.mNode.mPrev[-18].mNext;
        if ( v10 == (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)((char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList
                                                                                      - 280) )
          return;
      }
      v14 = v12->mParts;
      while ( v14[v11].mSimObject.m_pPointer != v7 )
      {
        if ( ++v11 >= v13 )
          goto LABEL_8;
      }
      hkpPhysicsSystem::hkpPhysicsSystem(&bodiesOut);
      UFG::Destruction::ForceFracture(UFG::Destruction::mInstance, v8, &bodiesOut, v11);
      if ( bodiesOut.m_rigidBodies.m_size > 0 )
      {
        v15 = 0i64;
        do
        {
          v16 = bodiesOut.m_rigidBodies.m_data[v15];
          a.m_rotation.m_col0 = v16->m_motion.m_motionState.m_transform.m_rotation.m_col0;
          a.m_rotation.m_col1 = v16->m_motion.m_motionState.m_transform.m_rotation.m_col1;
          a.m_rotation.m_col2 = v16->m_motion.m_motionState.m_transform.m_rotation.m_col2;
          a.m_translation = v16->m_motion.m_motionState.m_transform.m_translation;
          if ( v4 )
          {
            v17 = v16->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal.m_quad.m128_f32[1] + v5->y;
            v18 = v16->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal.m_quad.m128_f32[2] + v5->z;
            v5->x = v16->m_motion.m_motionState.m_sweptTransform.m_centerOfMassLocal.m_quad.m128_f32[0] + v5->x;
            v5->y = v17;
            v5->z = v18;
          }
          v22.m_quad = _mm_unpacklo_ps(
                         _mm_unpacklo_ps((__m128)LODWORD(v6->x), (__m128)LODWORD(v6->z)),
                         _mm_unpacklo_ps((__m128)LODWORD(v6->y), (__m128)0i64));
          b.m_quad = _mm_unpacklo_ps(
                       _mm_unpacklo_ps((__m128)LODWORD(v5->x), (__m128)LODWORD(v5->z)),
                       _mm_unpacklo_ps((__m128)LODWORD(v5->y), (__m128)0i64));
          hkVector4f::setTransformedPos(&v19, &a, &b);
          hkVector4f::setRotatedDir(&v21, (hkMatrix3f *)&a.m_rotation.m_col0, &v22);
          hkpEntity::activate((hkpEntity *)&v16->vfptr);
          ((void (__fastcall *)(hkpMaxSizeMotion *, hkVector4f *, hkVector4f *))v16->m_motion.vfptr[11].__first_virtual_table_function__)(
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
UFG::Constraint *__fastcall UFG::CreateConstraint_Util(hkpRigidBody *havokRigidBody1, hkpRigidBody *havokRigidBody2, UFG::qVector3 *pivotWorldConstraint)
{
  hkpRigidBody *v3; // rbp
  hkpRigidBody *v4; // r14
  _QWORD **v5; // rax
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
  hkVector4f pivotInB; // [rsp+40h] [rbp-48h]
  hkVector4f pivotInA; // [rsp+50h] [rbp-38h]
  UFG::qSymbol result; // [rsp+90h] [rbp+8h]
  UFG::allocator::free_link *v20; // [rsp+98h] [rbp+10h]
  UFG::qVector3 *_name; // [rsp+A0h] [rbp+18h]
  UFG::qVector3 **v22; // [rsp+A8h] [rbp+20h]

  _name = pivotWorldConstraint;
  v3 = havokRigidBody2;
  v4 = havokRigidBody1;
  v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v6 = (hkpBallSocketChainData *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v5[11] + 8i64))(v5[11], 112i64);
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
  v11 = (hkpConstraintChainInstance *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v10[11] + 8i64))(
                                        v10[11],
                                        144i64);
  _name = (UFG::qVector3 *)v11;
  if ( v11 )
  {
    hkpConstraintChainInstance::hkpConstraintChainInstance(v11, (hkpConstraintChainData *)&v9->vfptr);
    v13 = v12;
  }
  else
  {
    v13 = 0i64;
  }
  hkpConstraintChainInstance::addEntity(v13, (hkpEntity *)&v4->vfptr);
  pivotInB.m_quad = 0i64;
  pivotInA.m_quad = 0i64;
  hkpBallSocketChainData::addConstraintInfoInBodySpace(v9, &pivotInA, &pivotInB);
  hkpConstraintChainInstance::addEntity(v13, (hkpEntity *)&v3->vfptr);
  hkReferencedObject::removeReference((hkReferencedObject *)&v9->vfptr);
  UFG::qSymbol::create_from_string(&result, "CreateConstraint_Util");
  v14 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x60ui64, "Constraint", 0i64, 1u);
  v20 = v14;
  if ( v14 )
  {
    v22 = &_name;
    LODWORD(_name) = result;
    UFG::Constraint::Constraint((UFG::Constraint *)v14, (__int64)&_name);
    v7 = v15;
  }
  *(_QWORD *)(v7 + 40) = v13;
  return (UFG::Constraint *)v7;
}

