// File Line: 25
// RVA: 0x472810
void PhysicsSkookum::RegisterMethods(void)
{
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "create_stiff_spring_constraint",
    PhysicsSkookum::MthdC_create_stiff_spring_constraint,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "create_fixed_constraint",
    PhysicsSkookum::MthdC_create_fixed_constraint,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "create_ball_and_socket_constraint",
    PhysicsSkookum::MthdC_create_ball_and_socket_constraint,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "delete_constraint",
    PhysicsSkookum::MthdC_delete_constraint,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "damage_destructible",
    PhysicsSkookum::MthdC_damage_destructible,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "shear_object",
    PhysicsSkookum::MthdC_shear_object,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "enable_fracture",
    PhysicsSkookum::MthdC_enable_fracture,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&SSBrain::c_world_class_p->vfptr,
    "disable_fracture",
    PhysicsSkookum::MthdC_disable_fracture,
    1,
    0);
}

// File Line: 41
// RVA: 0x46D100
void __fastcall PhysicsSkookum::MthdC_create_stiff_spring_constraint(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // r8
  SSInvokedMethod *v3; // rdi
  int v4; // xmm6_4
  UFG::SimObject *v5; // rax
  SSData **v6; // r8
  UFG::SimObjectGame *v7; // r15
  int v8; // ebx
  float *v9; // rcx
  float v10; // xmm1_4
  float v11; // xmm2_4
  UFG::SimObject *v12; // rax
  SSData **v13; // r8
  hkpRigidBody *v14; // r12
  UFG::RigidBody *v15; // r14
  UFG::RigidBody *v16; // rsi
  UFG::SimObjectGame *v17; // rbp
  int v18; // edi
  SSInstance *v19; // rdx
  float *v20; // rcx
  float v21; // xmm1_4
  float v22; // xmm2_4
  unsigned __int16 v23; // cx
  UFG::SimComponent *v24; // rax
  UFG::TransformNodeComponent *v25; // rcx
  unsigned __int16 v26; // cx
  UFG::SimComponent *v27; // rax
  UFG::TransformNodeComponent *v28; // rcx
  __int64 v29; // rdx
  hkpRigidBody *v30; // rdi
  UFG::Constraint *v31; // rbx
  UFG::qVector3 pivot2; // [rsp+30h] [rbp-58h]
  UFG::qVector3 pivot1; // [rsp+40h] [rbp-48h]
  UFG::qSymbol name; // [rsp+90h] [rbp+8h]

  v2 = pScope->i_data.i_array_p;
  v3 = pScope;
  name.mUID = (*v2)->i_data_p->i_user_data;
  v4 = v2[1]->i_data_p->i_user_data;
  v5 = UFG::TSSimObject::GetArgByNameOrInstance((SSInvokedContextBase *)&pScope->vfptr, 2u);
  v6 = v3->i_data.i_array_p;
  v7 = (UFG::SimObjectGame *)v5;
  v8 = v6[3]->i_data_p->i_user_data;
  v9 = (float *)v6[4]->i_data_p->i_user_data;
  v10 = v9[1];
  v11 = v9[2];
  pivot1.x = *v9;
  pivot1.y = v10;
  pivot1.z = v11;
  v12 = UFG::TSSimObject::GetArgByNameOrInstance((SSInvokedContextBase *)&v3->vfptr, 5u);
  v13 = v3->i_data.i_array_p;
  v14 = 0i64;
  v15 = 0i64;
  v16 = 0i64;
  v17 = (UFG::SimObjectGame *)v12;
  v18 = v13[6]->i_data_p->i_user_data;
  v19 = v13[7]->i_data_p;
  v20 = (float *)v19->i_user_data;
  v21 = v20[1];
  v22 = v20[2];
  pivot2.x = *v20;
  pivot2.y = v21;
  pivot2.z = v22;
  if ( v7 )
  {
    v23 = v7->m_Flags;
    if ( (v23 >> 14) & 1 )
    {
      v24 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
    }
    else if ( (v23 & 0x8000u) == 0 )
    {
      if ( (v23 >> 13) & 1 )
        v24 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
      else
        v24 = (v23 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::RigidBodyComponent::_TypeUID);
    }
    else
    {
      v24 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::RigidBodyComponent::_TypeUID);
    }
    v25 = (UFG::TransformNodeComponent *)v24;
    if ( v24 )
    {
      while ( v8 && *(_DWORD *)(*(_QWORD *)&v25->mWorldTransform.v2.x + 216i64) != v8 )
      {
        v25 = UFG::SimObject::GetComponentOfType(
                v25->m_pSimObject,
                UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                0,
                (UFG::SimComponent *)&v25->vfptr);
        if ( !v25 )
          goto LABEL_17;
      }
      v15 = (UFG::RigidBody *)v25;
    }
  }
LABEL_17:
  if ( v17 )
  {
    v26 = v17->m_Flags;
    if ( (v26 >> 14) & 1 )
    {
      v27 = UFG::SimObjectGame::GetComponentOfTypeHK(v17, UFG::RigidBodyComponent::_TypeUID);
    }
    else if ( (v26 & 0x8000u) == 0 )
    {
      if ( (v26 >> 13) & 1 )
        v27 = UFG::SimObjectGame::GetComponentOfTypeHK(v17, UFG::RigidBodyComponent::_TypeUID);
      else
        v27 = (v26 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v17, UFG::RigidBodyComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v17->vfptr, UFG::RigidBodyComponent::_TypeUID);
    }
    else
    {
      v27 = UFG::SimObjectGame::GetComponentOfTypeHK(v17, UFG::RigidBodyComponent::_TypeUID);
    }
    v28 = (UFG::TransformNodeComponent *)v27;
    if ( v27 )
    {
      while ( v18 && *(_DWORD *)(*(_QWORD *)&v28->mWorldTransform.v2.x + 216i64) != v18 )
      {
        v28 = UFG::SimObject::GetComponentOfType(
                v28->m_pSimObject,
                UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                0,
                (UFG::SimComponent *)&v28->vfptr);
        if ( !v28 )
          goto LABEL_33;
      }
      v16 = (UFG::RigidBody *)v28;
    }
  }
LABEL_33:
  if ( v15 )
  {
    LOBYTE(v19) = 1;
    v15->vfptr[15].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v15->vfptr, (unsigned int)v19);
    v15->mFlags &= 0xFFFFFFFE;
    v30 = v15->mBody;
    if ( v16 )
    {
      LOBYTE(v29) = 1;
      v16->vfptr[15].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v16->vfptr, v29);
      v16->mFlags &= 0xFFFFFFFE;
      v14 = v16->mBody;
    }
    if ( v30 )
    {
      v31 = UFG::Constraint::CreateStiffSpringContraint(v30, v14, &name, &pivot1, &pivot2);
      UFG::RigidBody::AddConstraint(v15, v31);
      hkpEntity::activate((hkpEntity *)&v30->vfptr);
      if ( v16 )
      {
        UFG::RigidBody::AddConstraint(v16, v31);
        hkpEntity::activate((hkpEntity *)&v14->vfptr);
      }
      UFG::BasePhysicsSystem::AddConstraint(UFG::BasePhysicsSystem::mInstance, v31->mConstraintInstance);
    }
  }
}

// File Line: 117
// RVA: 0x46CE80
void __fastcall PhysicsSkookum::MthdC_create_fixed_constraint(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rdi
  UFG::SimObjectGame *v3; // rbp
  int v4; // ebx
  UFG::SimObject *v5; // rax
  UFG::RigidBody *v6; // r14
  __int64 v7; // rdx
  UFG::RigidBody *v8; // r15
  UFG::SimObjectGame *v9; // rsi
  int v10; // edi
  unsigned __int16 v11; // dx
  UFG::SimComponent *v12; // rax
  UFG::TransformNodeComponent *v13; // rcx
  unsigned __int16 v14; // cx
  UFG::TransformNodeComponent *v15; // rax
  hkpRigidBody *v16; // rsi
  __int64 v17; // rdx
  hkpEntity *v18; // rdi
  UFG::Constraint *v19; // rbx
  UFG::qSymbol name; // [rsp+40h] [rbp+8h]

  v2 = pScope;
  name.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = (UFG::SimObjectGame *)UFG::TSSimObject::GetArgByNameOrInstance((SSInvokedContextBase *)&pScope->vfptr, 1u);
  v4 = *(_DWORD *)(*(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 2) + 8i64) + 32i64);
  v5 = UFG::TSSimObject::GetArgByNameOrInstance((SSInvokedContextBase *)&v2->vfptr, 3u);
  v6 = 0i64;
  v7 = *((_QWORD *)v2->i_data.i_array_p + 4);
  v8 = 0i64;
  v9 = (UFG::SimObjectGame *)v5;
  v10 = *(_DWORD *)(*(_QWORD *)(v7 + 8) + 32i64);
  if ( v3 )
  {
    v11 = v3->m_Flags;
    if ( (v3->m_Flags >> 14) & 1 )
    {
      v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RigidBodyComponent::_TypeUID);
    }
    else if ( (v11 & 0x8000u) == 0 )
    {
      if ( (v11 >> 13) & 1 )
        v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RigidBodyComponent::_TypeUID);
      else
        v12 = (v11 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RigidBodyComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::RigidBodyComponent::_TypeUID);
    }
    else
    {
      v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RigidBodyComponent::_TypeUID);
    }
    v13 = (UFG::TransformNodeComponent *)v12;
    if ( v12 )
    {
      while ( v4 && *(_DWORD *)(*(_QWORD *)&v13->mWorldTransform.v2.x + 216i64) != v4 )
      {
        v13 = UFG::SimObject::GetComponentOfType(
                v13->m_pSimObject,
                UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                0,
                (UFG::SimComponent *)&v13->vfptr);
        if ( !v13 )
          goto LABEL_17;
      }
      v6 = (UFG::RigidBody *)v13;
    }
  }
LABEL_17:
  if ( v9 )
  {
    v14 = v9->m_Flags;
    if ( (v14 >> 14) & 1 )
    {
      v15 = (UFG::TransformNodeComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             v9,
                                             UFG::RigidBodyComponent::_TypeUID);
    }
    else if ( (v14 & 0x8000u) == 0 )
    {
      if ( (v14 >> 13) & 1 )
        v15 = (UFG::TransformNodeComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               v9,
                                               UFG::RigidBodyComponent::_TypeUID);
      else
        v15 = (UFG::TransformNodeComponent *)((v14 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                  v9,
                                                                  UFG::RigidBodyComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v9->vfptr, UFG::RigidBodyComponent::_TypeUID));
    }
    else
    {
      v15 = (UFG::TransformNodeComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             v9,
                                             UFG::RigidBodyComponent::_TypeUID);
    }
    if ( v15 )
    {
      while ( v10 && *(_DWORD *)(*(_QWORD *)&v15->mWorldTransform.v2.x + 216i64) != v10 )
      {
        v15 = UFG::SimObject::GetComponentOfType(
                v15->m_pSimObject,
                UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                0,
                (UFG::SimComponent *)&v15->vfptr);
        if ( !v15 )
          goto LABEL_33;
      }
      v8 = (UFG::RigidBody *)v15;
    }
  }
LABEL_33:
  if ( v6 )
  {
    if ( v8 )
    {
      LOBYTE(v7) = 1;
      v6->vfptr[15].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v6->vfptr, v7);
      v6->mFlags &= 0xFFFFFFFE;
      v16 = v6->mBody;
      LOBYTE(v17) = 1;
      v8->vfptr[15].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v8->vfptr, v17);
      v8->mFlags &= 0xFFFFFFFE;
      v18 = (hkpEntity *)&v8->mBody->vfptr;
      if ( v16 )
      {
        if ( v18 )
        {
          v19 = UFG::Constraint::CreateFixedContraint(v16, v8->mBody, &name);
          UFG::RigidBody::AddConstraint(v6, v19);
          UFG::RigidBody::AddConstraint(v8, v19);
          hkpEntity::activate((hkpEntity *)&v16->vfptr);
          hkpEntity::activate(v18);
          UFG::BasePhysicsSystem::AddConstraint(UFG::BasePhysicsSystem::mInstance, v19->mConstraintInstance);
        }
      }
    }
  }
}

// File Line: 184
// RVA: 0x46CBD0
void __fastcall PhysicsSkookum::MthdC_create_ball_and_socket_constraint(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rdi
  UFG::SimObject *v3; // rax
  SSData **v4; // rcx
  UFG::SimObjectGame *v5; // r15
  SSInstance *v6; // r8
  float *v7; // rcx
  int v8; // ebx
  float v9; // xmm1_4
  float v10; // xmm2_4
  UFG::SimObject *v11; // rax
  hkpRigidBody *v12; // r12
  __int64 v13; // rdx
  UFG::RigidBody *v14; // r14
  UFG::RigidBody *v15; // rsi
  UFG::SimObjectGame *v16; // rbp
  int v17; // edi
  unsigned __int16 v18; // dx
  UFG::SimComponent *v19; // rax
  UFG::TransformNodeComponent *v20; // rcx
  unsigned __int16 v21; // cx
  UFG::SimComponent *v22; // rax
  UFG::TransformNodeComponent *v23; // rcx
  __int64 v24; // rdx
  hkpRigidBody *v25; // rdi
  UFG::Constraint *v26; // rbx
  UFG::qVector3 pivot; // [rsp+20h] [rbp-38h]
  UFG::qSymbol name; // [rsp+60h] [rbp+8h]

  v2 = pScope;
  name.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = UFG::TSSimObject::GetArgByNameOrInstance((SSInvokedContextBase *)&pScope->vfptr, 1u);
  v4 = v2->i_data.i_array_p;
  v5 = (UFG::SimObjectGame *)v3;
  v6 = v4[2]->i_data_p;
  v7 = (float *)v4[3]->i_data_p->i_user_data;
  v8 = v6->i_user_data;
  v9 = v7[1];
  v10 = v7[2];
  pivot.x = *v7;
  pivot.y = v9;
  pivot.z = v10;
  v11 = UFG::TSSimObject::GetArgByNameOrInstance((SSInvokedContextBase *)&v2->vfptr, 4u);
  v12 = 0i64;
  v13 = *((_QWORD *)v2->i_data.i_array_p + 5);
  v14 = 0i64;
  v15 = 0i64;
  v16 = (UFG::SimObjectGame *)v11;
  v17 = *(_DWORD *)(*(_QWORD *)(v13 + 8) + 32i64);
  if ( v5 )
  {
    v18 = v5->m_Flags;
    if ( (v5->m_Flags >> 14) & 1 )
    {
      v19 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::RigidBodyComponent::_TypeUID);
    }
    else if ( (v18 & 0x8000u) == 0 )
    {
      if ( (v18 >> 13) & 1 )
        v19 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::RigidBodyComponent::_TypeUID);
      else
        v19 = (v18 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::RigidBodyComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::RigidBodyComponent::_TypeUID);
    }
    else
    {
      v19 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::RigidBodyComponent::_TypeUID);
    }
    v20 = (UFG::TransformNodeComponent *)v19;
    if ( v19 )
    {
      while ( v8 && *(_DWORD *)(*(_QWORD *)&v20->mWorldTransform.v2.x + 216i64) != v8 )
      {
        v20 = UFG::SimObject::GetComponentOfType(
                v20->m_pSimObject,
                UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                0,
                (UFG::SimComponent *)&v20->vfptr);
        if ( !v20 )
          goto LABEL_17;
      }
      v14 = (UFG::RigidBody *)v20;
    }
  }
LABEL_17:
  if ( v16 )
  {
    v21 = v16->m_Flags;
    if ( (v21 >> 14) & 1 )
    {
      v22 = UFG::SimObjectGame::GetComponentOfTypeHK(v16, UFG::RigidBodyComponent::_TypeUID);
    }
    else if ( (v21 & 0x8000u) == 0 )
    {
      if ( (v21 >> 13) & 1 )
        v22 = UFG::SimObjectGame::GetComponentOfTypeHK(v16, UFG::RigidBodyComponent::_TypeUID);
      else
        v22 = (v21 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v16, UFG::RigidBodyComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v16->vfptr, UFG::RigidBodyComponent::_TypeUID);
    }
    else
    {
      v22 = UFG::SimObjectGame::GetComponentOfTypeHK(v16, UFG::RigidBodyComponent::_TypeUID);
    }
    v23 = (UFG::TransformNodeComponent *)v22;
    if ( v22 )
    {
      while ( v17 && *(_DWORD *)(*(_QWORD *)&v23->mWorldTransform.v2.x + 216i64) != v17 )
      {
        v23 = UFG::SimObject::GetComponentOfType(
                v23->m_pSimObject,
                UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                0,
                (UFG::SimComponent *)&v23->vfptr);
        if ( !v23 )
          goto LABEL_33;
      }
      v15 = (UFG::RigidBody *)v23;
    }
  }
LABEL_33:
  if ( v14 )
  {
    LOBYTE(v13) = 1;
    v14->vfptr[15].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v14->vfptr, v13);
    v14->mFlags &= 0xFFFFFFFE;
    v25 = v14->mBody;
    if ( v15 )
    {
      LOBYTE(v24) = 1;
      v15->vfptr[15].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v15->vfptr, v24);
      v15->mFlags &= 0xFFFFFFFE;
      v12 = v15->mBody;
    }
    if ( v25 )
    {
      v26 = UFG::Constraint::CreateBallAndSocketConstraint(v25, v12, &name, &pivot);
      UFG::RigidBody::AddConstraint(v14, v26);
      hkpEntity::activate((hkpEntity *)&v25->vfptr);
      if ( v15 )
      {
        UFG::RigidBody::AddConstraint(v15, v26);
        hkpEntity::activate((hkpEntity *)&v12->vfptr);
      }
      UFG::BasePhysicsSystem::AddConstraint(UFG::BasePhysicsSystem::mInstance, v26->mConstraintInstance);
    }
  }
}

// File Line: 257
// RVA: 0x46D4D0
void __fastcall PhysicsSkookum::MthdC_delete_constraint(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::SimObjectGame *v3; // rax
  SSData **v4; // r8
  int v5; // ebx
  unsigned int v6; // edi
  unsigned __int16 v7; // cx
  UFG::SimComponent *v8; // rax
  UFG::RigidBody *v9; // rsi
  hkpEntity *v10; // rcx
  UFG::Constraint *v11; // rax
  UFG::Constraint *v12; // rbx
  __int64 v13; // rdx
  hkpEntity *v14; // rcx
  UFG::qSymbol name; // [rsp+40h] [rbp+8h]
  UFG::qSymbol *v16; // [rsp+50h] [rbp+18h]

  v2 = pScope;
  v3 = (UFG::SimObjectGame *)UFG::TSSimObject::GetArgByNameOrInstance((SSInvokedContextBase *)&pScope->vfptr, 0);
  v4 = v2->i_data.i_array_p;
  v5 = v4[1]->i_data_p->i_user_data;
  v6 = v4[2]->i_data_p->i_user_data;
  if ( v3 )
  {
    v7 = v3->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RigidBodyComponent::_TypeUID);
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RigidBodyComponent::_TypeUID);
      else
        v8 = (v7 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RigidBodyComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::RigidBodyComponent::_TypeUID);
    }
    else
    {
      v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RigidBodyComponent::_TypeUID);
    }
    v9 = (UFG::RigidBody *)v8;
    if ( v8 )
    {
      while ( v5 && v9->mCollisionMeshData->mName.mUID != v5 )
      {
        v9 = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                 v9->m_pSimObject,
                                 UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                                 0,
                                 (UFG::SimComponent *)&v9->vfptr);
        if ( !v9 )
          return;
      }
      if ( v9 )
      {
        if ( v6 )
        {
          v16 = &name;
          name.mUID = v6;
          v11 = UFG::RigidBody::GetConstraintByName(v9, (__int64)&name);
          v12 = v11;
          if ( v11 )
          {
            UFG::BasePhysicsSystem::RemoveConstraint(UFG::BasePhysicsSystem::mInstance, v11->mConstraintInstance);
            UFG::RigidBody::RemoveConstraint(v9, v12);
            LOBYTE(v13) = 1;
            v9->vfptr[15].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v9->vfptr, v13);
            v14 = (hkpEntity *)&v9->mBody->vfptr;
            if ( v14 )
              hkpEntity::activate(v14);
            v12->vfptr->__vecDelDtor((UFG::qSafePointerNode<UFG::Constraint> *)&v12->vfptr, 1u);
          }
        }
        else
        {
          UFG::RigidBody::DeleteAllConstraints(v9);
          v10 = (hkpEntity *)&v9->mBody->vfptr;
          if ( v10 )
            hkpEntity::activate(v10);
        }
      }
    }
  }
}

// File Line: 319
// RVA: 0x46D400
void __fastcall PhysicsSkookum::MthdC_damage_destructible(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rdx
  float v3; // xmm6_4
  unsigned int v4; // eax
  UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *v5; // rdx
  UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> *v6; // rax
  float v7; // xmm0_4
  UFG::qSymbol result; // [rsp+40h] [rbp+8h]

  v2 = pScope->i_data.i_array_p;
  v3 = *(float *)&v2[1]->i_data_p->i_user_data;
  v4 = UFG::qSymbol::create_from_string(&result, *(const char **)(*v2)->i_data_p->i_user_data)->mUID;
  v5 = (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)&UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext;
  if ( &UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext != (UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> **)((char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList - 280) )
  {
    while ( LODWORD(v5[2].mNode.mNext[4].mNext) != v4 )
    {
      v5 = (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)&v5[18].mNode.mPrev[-18].mNext;
      if ( v5 == (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)((char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList
                                                                                   - 280) )
        return;
    }
    v6 = v5[24].mNode.mPrev;
    if ( v6 && v3 > 0.0 && v6[9].mNext )
    {
      v7 = *((float *)&v6[16].mNext + 1) - v3;
      *((float *)&v6[16].mNext + 1) = v7;
      if ( v7 < 0.0 )
        HIDWORD(v6[16].mNext) = 0;
    }
  }
}

// File Line: 347
// RVA: 0x46D750
void __fastcall PhysicsSkookum::MthdC_shear_object(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::SimObject *v3; // r10
  SSData **v4; // r8
  int *v5; // rcx
  int v6; // xmm1_4
  int v7; // xmm0_4
  SSInstance *v8; // rax
  int *v9; // rcx
  int v10; // xmm1_4
  int v11; // xmm2_4
  int v12; // [rsp+20h] [rbp-28h]
  int v13; // [rsp+24h] [rbp-24h]
  int v14; // [rsp+28h] [rbp-20h]
  int v15; // [rsp+30h] [rbp-18h]
  int v16; // [rsp+34h] [rbp-14h]
  int v17; // [rsp+38h] [rbp-10h]

  v2 = pScope;
  v3 = UFG::TSSimObject::GetArgByNameOrInstance((SSInvokedContextBase *)&pScope->vfptr, 0);
  if ( v3 )
  {
    v4 = v2->i_data.i_array_p;
    v5 = (int *)v4[1]->i_data_p->i_user_data;
    v6 = v5[1];
    v15 = *v5;
    v7 = v5[2];
    v16 = v6;
    v8 = v4[2]->i_data_p;
    v17 = v7;
    v9 = (int *)v8->i_user_data;
    v10 = v9[1];
    v11 = v9[2];
    v12 = *v9;
    v13 = v10;
    v14 = v11;
    UFG::ShearObject(v3, (UFG::qVector3 *)&v15, (UFG::qVector3 *)&v12, v9 != 0i64);
  }
}

// File Line: 363
// RVA: 0x46D6D0
void __fastcall PhysicsSkookum::MthdC_enable_fracture(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *v2; // rcx
  UFG::qSymbol result; // [rsp+30h] [rbp+8h]

  UFG::qSymbol::create_from_string(&result, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  v2 = (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)&UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext;
  if ( &UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext != (UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> **)((char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList - 280) )
  {
    while ( LODWORD(v2[2].mNode.mNext[4].mNext) != result.mUID )
    {
      v2 = (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)&v2[18].mNode.mPrev[-18].mNext;
      if ( v2 == (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)((char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList
                                                                                   - 280) )
        return;
    }
    UFG::RigidBody::EnableFractureParts((UFG::RigidBody *)v2, 0);
  }
}

// File Line: 385
// RVA: 0x46D660
void __fastcall PhysicsSkookum::MthdC_disable_fracture(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *v2; // rcx
  UFG::qSymbol result; // [rsp+30h] [rbp+8h]

  UFG::qSymbol::create_from_string(&result, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  v2 = (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)&UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext;
  if ( &UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext != (UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> **)((char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList - 280) )
  {
    while ( LODWORD(v2[2].mNode.mNext[4].mNext) != result.mUID )
    {
      v2 = (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)&v2[18].mNode.mPrev[-18].mNext;
      if ( v2 == (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)((char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList
                                                                                   - 280) )
        return;
    }
    UFG::RigidBody::DisableFractureParts((UFG::RigidBody *)v2);
  }
}

