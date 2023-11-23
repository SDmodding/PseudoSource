// File Line: 25
// RVA: 0x472810
void PhysicsSkookum::RegisterMethods(void)
{
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]
  ASymbol rebindb; // [rsp+20h] [rbp-18h]
  ASymbol rebindc; // [rsp+20h] [rbp-18h]
  ASymbol rebindd; // [rsp+20h] [rbp-18h]
  ASymbol rebinde; // [rsp+20h] [rbp-18h]
  ASymbol rebindf; // [rsp+20h] [rbp-18h]
  ASymbol rebindg; // [rsp+20h] [rbp-18h]

  LOBYTE(rebind.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "create_stiff_spring_constraint",
    PhysicsSkookum::MthdC_create_stiff_spring_constraint,
    1,
    rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "create_fixed_constraint",
    PhysicsSkookum::MthdC_create_fixed_constraint,
    1,
    rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "create_ball_and_socket_constraint",
    PhysicsSkookum::MthdC_create_ball_and_socket_constraint,
    1,
    rebindb);
  LOBYTE(rebindc.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "delete_constraint",
    PhysicsSkookum::MthdC_delete_constraint,
    1,
    rebindc);
  LOBYTE(rebindd.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "damage_destructible",
    PhysicsSkookum::MthdC_damage_destructible,
    1,
    rebindd);
  LOBYTE(rebinde.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "shear_object",
    PhysicsSkookum::MthdC_shear_object,
    1,
    rebinde);
  LOBYTE(rebindf.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "enable_fracture",
    PhysicsSkookum::MthdC_enable_fracture,
    1,
    rebindf);
  LOBYTE(rebindg.i_uid) = 0;
  SSClass::register_method_func(
    SSBrain::c_world_class_p,
    "disable_fracture",
    PhysicsSkookum::MthdC_disable_fracture,
    1,
    rebindg);
}

// File Line: 41
// RVA: 0x46D100
void __fastcall PhysicsSkookum::MthdC_create_stiff_spring_constraint(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *ArgByNameOrInstance; // rax
  SSData **i_array_p; // r8
  UFG::SimObjectGame *v5; // r15
  int i_user_data; // ebx
  float *v7; // rcx
  float v8; // xmm1_4
  float v9; // xmm2_4
  UFG::SimObject *v10; // rax
  SSData **v11; // r8
  hkpRigidBody *v12; // r12
  UFG::RigidBody *v13; // r14
  UFG::RigidBody *v14; // rsi
  UFG::SimObjectGame *v15; // rbp
  int v16; // edi
  SSInstance *i_data_p; // rdx
  float *v18; // rcx
  float v19; // xmm1_4
  float v20; // xmm2_4
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::TransformNodeComponent *ComponentOfType; // rcx
  __int16 v24; // cx
  UFG::SimComponent *v25; // rax
  UFG::TransformNodeComponent *v26; // rcx
  __int64 v27; // rdx
  hkpRigidBody *mBody; // rdi
  UFG::Constraint *v29; // rbx
  UFG::qVector3 pivot2; // [rsp+30h] [rbp-58h] BYREF
  UFG::qVector3 pivot1; // [rsp+40h] [rbp-48h] BYREF
  UFG::qSymbol name; // [rsp+90h] [rbp+8h] BYREF

  name.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  ArgByNameOrInstance = UFG::TSSimObject::GetArgByNameOrInstance(pScope, 2u);
  i_array_p = pScope->i_data.i_array_p;
  v5 = (UFG::SimObjectGame *)ArgByNameOrInstance;
  i_user_data = i_array_p[3]->i_data_p->i_user_data;
  v7 = (float *)i_array_p[4]->i_data_p->i_user_data;
  v8 = v7[1];
  v9 = v7[2];
  pivot1.x = *v7;
  pivot1.y = v8;
  pivot1.z = v9;
  v10 = UFG::TSSimObject::GetArgByNameOrInstance(pScope, 5u);
  v11 = pScope->i_data.i_array_p;
  v12 = 0i64;
  v13 = 0i64;
  v14 = 0i64;
  v15 = (UFG::SimObjectGame *)v10;
  v16 = v11[6]->i_data_p->i_user_data;
  i_data_p = v11[7]->i_data_p;
  v18 = (float *)i_data_p->i_user_data;
  v19 = v18[1];
  v20 = v18[2];
  pivot2.x = *v18;
  pivot2.y = v19;
  pivot2.z = v20;
  if ( v5 )
  {
    m_Flags = v5->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::RigidBodyComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v5, UFG::RigidBodyComponent::_TypeUID);
    ComponentOfType = (UFG::TransformNodeComponent *)ComponentOfTypeHK;
    if ( ComponentOfTypeHK )
    {
      while ( i_user_data && *(_DWORD *)(*(_QWORD *)&ComponentOfType->mWorldTransform.v2.x + 216i64) != i_user_data )
      {
        ComponentOfType = UFG::SimObject::GetComponentOfType(
                            ComponentOfType->m_pSimObject,
                            UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                            0,
                            ComponentOfType);
        if ( !ComponentOfType )
          goto LABEL_15;
      }
      v13 = (UFG::RigidBody *)ComponentOfType;
    }
  }
LABEL_15:
  if ( v15 )
  {
    v24 = v15->m_Flags;
    if ( (v24 & 0x4000) != 0 || v24 < 0 || (v24 & 0x2000) != 0 || (v24 & 0x1000) != 0 )
      v25 = UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::RigidBodyComponent::_TypeUID);
    else
      v25 = UFG::SimObject::GetComponentOfType(v15, UFG::RigidBodyComponent::_TypeUID);
    v26 = (UFG::TransformNodeComponent *)v25;
    if ( v25 )
    {
      while ( v16 && *(_DWORD *)(*(_QWORD *)&v26->mWorldTransform.v2.x + 216i64) != v16 )
      {
        v26 = UFG::SimObject::GetComponentOfType(
                v26->m_pSimObject,
                UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                0,
                v26);
        if ( !v26 )
          goto LABEL_29;
      }
      v14 = (UFG::RigidBody *)v26;
    }
  }
LABEL_29:
  if ( v13 )
  {
    LOBYTE(i_data_p) = 1;
    v13->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[15].__vecDelDtor(
      v13,
      (unsigned int)i_data_p);
    v13->mFlags &= ~1u;
    mBody = v13->mBody;
    if ( v14 )
    {
      LOBYTE(v27) = 1;
      v14->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[15].__vecDelDtor(v14, v27);
      v14->mFlags &= ~1u;
      v12 = v14->mBody;
    }
    if ( mBody )
    {
      v29 = UFG::Constraint::CreateStiffSpringContraint(mBody, v12, &name, &pivot1, &pivot2);
      UFG::RigidBody::AddConstraint(v13, v29);
      hkpEntity::activate(mBody);
      if ( v14 )
      {
        UFG::RigidBody::AddConstraint(v14, v29);
        hkpEntity::activate(v12);
      }
      UFG::BasePhysicsSystem::AddConstraint(UFG::BasePhysicsSystem::mInstance, v29->mConstraintInstance);
    }
  }
}

// File Line: 117
// RVA: 0x46CE80
void __fastcall PhysicsSkookum::MthdC_create_fixed_constraint(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectGame *ArgByNameOrInstance; // rbp
  int v4; // ebx
  UFG::SimObject *v5; // rax
  UFG::RigidBody *v6; // r14
  __int64 v7; // rdx
  UFG::RigidBody *v8; // r15
  UFG::SimObjectGame *v9; // rsi
  int v10; // edi
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::TransformNodeComponent *ComponentOfType; // rcx
  __int16 v14; // cx
  UFG::TransformNodeComponent *v15; // rax
  hkpRigidBody *mBody; // rsi
  __int64 v17; // rdx
  hkpEntity *v18; // rdi
  UFG::Constraint *v19; // rbx
  UFG::qSymbol name; // [rsp+40h] [rbp+8h] BYREF

  name.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  ArgByNameOrInstance = (UFG::SimObjectGame *)UFG::TSSimObject::GetArgByNameOrInstance(pScope, 1u);
  v4 = *(_DWORD *)(*(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 2) + 8i64) + 32i64);
  v5 = UFG::TSSimObject::GetArgByNameOrInstance(pScope, 3u);
  v6 = 0i64;
  v7 = *((_QWORD *)pScope->i_data.i_array_p + 4);
  v8 = 0i64;
  v9 = (UFG::SimObjectGame *)v5;
  v10 = *(_DWORD *)(*(_QWORD *)(v7 + 8) + 32i64);
  if ( ArgByNameOrInstance )
  {
    m_Flags = ArgByNameOrInstance->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                            ArgByNameOrInstance,
                            UFG::RigidBodyComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(ArgByNameOrInstance, UFG::RigidBodyComponent::_TypeUID);
    ComponentOfType = (UFG::TransformNodeComponent *)ComponentOfTypeHK;
    if ( ComponentOfTypeHK )
    {
      while ( v4 && *(_DWORD *)(*(_QWORD *)&ComponentOfType->mWorldTransform.v2.x + 216i64) != v4 )
      {
        ComponentOfType = UFG::SimObject::GetComponentOfType(
                            ComponentOfType->m_pSimObject,
                            UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                            0,
                            ComponentOfType);
        if ( !ComponentOfType )
          goto LABEL_15;
      }
      v6 = (UFG::RigidBody *)ComponentOfType;
    }
  }
LABEL_15:
  if ( v9 )
  {
    v14 = v9->m_Flags;
    if ( (v14 & 0x4000) != 0 || v14 < 0 || (v14 & 0x2000) != 0 || (v14 & 0x1000) != 0 )
      v15 = (UFG::TransformNodeComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             v9,
                                             UFG::RigidBodyComponent::_TypeUID);
    else
      v15 = (UFG::TransformNodeComponent *)UFG::SimObject::GetComponentOfType(v9, UFG::RigidBodyComponent::_TypeUID);
    if ( v15 )
    {
      while ( v10 && *(_DWORD *)(*(_QWORD *)&v15->mWorldTransform.v2.x + 216i64) != v10 )
      {
        v15 = UFG::SimObject::GetComponentOfType(
                v15->m_pSimObject,
                UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                0,
                v15);
        if ( !v15 )
          goto LABEL_29;
      }
      v8 = (UFG::RigidBody *)v15;
    }
  }
LABEL_29:
  if ( v6 )
  {
    if ( v8 )
    {
      LOBYTE(v7) = 1;
      v6->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[15].__vecDelDtor(v6, v7);
      v6->mFlags &= ~1u;
      mBody = v6->mBody;
      LOBYTE(v17) = 1;
      v8->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[15].__vecDelDtor(v8, v17);
      v8->mFlags &= ~1u;
      v18 = v8->mBody;
      if ( mBody )
      {
        if ( v18 )
        {
          v19 = UFG::Constraint::CreateFixedContraint(mBody, v8->mBody, &name);
          UFG::RigidBody::AddConstraint(v6, v19);
          UFG::RigidBody::AddConstraint(v8, v19);
          hkpEntity::activate(mBody);
          hkpEntity::activate(v18);
          UFG::BasePhysicsSystem::AddConstraint(UFG::BasePhysicsSystem::mInstance, v19->mConstraintInstance);
        }
      }
    }
  }
}Constraint(UFG::BasePhysicsSystem::mInstance, v19->mConstraintInstance);
        }
      }

// File Line: 184
// RVA: 0x46CBD0
void __fastcall PhysicsSkookum::MthdC_create_ball_and_socket_constraint(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *ArgByNameOrInstance; // rax
  SSData **i_array_p; // rcx
  UFG::SimObjectGame *v5; // r15
  SSInstance *i_data_p; // r8
  float *i_user_data; // rcx
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
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::TransformNodeComponent *ComponentOfType; // rcx
  __int16 v21; // cx
  UFG::SimComponent *v22; // rax
  UFG::TransformNodeComponent *v23; // rcx
  __int64 v24; // rdx
  hkpRigidBody *mBody; // rdi
  UFG::Constraint *v26; // rbx
  UFG::qVector3 pivot; // [rsp+20h] [rbp-38h] BYREF
  UFG::qSymbol name; // [rsp+60h] [rbp+8h] BYREF

  name.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  ArgByNameOrInstance = UFG::TSSimObject::GetArgByNameOrInstance(pScope, 1u);
  i_array_p = pScope->i_data.i_array_p;
  v5 = (UFG::SimObjectGame *)ArgByNameOrInstance;
  i_data_p = i_array_p[2]->i_data_p;
  i_user_data = (float *)i_array_p[3]->i_data_p->i_user_data;
  v8 = i_data_p->i_user_data;
  v9 = i_user_data[1];
  v10 = i_user_data[2];
  pivot.x = *i_user_data;
  pivot.y = v9;
  pivot.z = v10;
  v11 = UFG::TSSimObject::GetArgByNameOrInstance(pScope, 4u);
  v12 = 0i64;
  v13 = *((_QWORD *)pScope->i_data.i_array_p + 5);
  v14 = 0i64;
  v15 = 0i64;
  v16 = (UFG::SimObjectGame *)v11;
  v17 = *(_DWORD *)(*(_QWORD *)(v13 + 8) + 32i64);
  if ( v5 )
  {
    m_Flags = v5->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::RigidBodyComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v5, UFG::RigidBodyComponent::_TypeUID);
    ComponentOfType = (UFG::TransformNodeComponent *)ComponentOfTypeHK;
    if ( ComponentOfTypeHK )
    {
      while ( v8 && *(_DWORD *)(*(_QWORD *)&ComponentOfType->mWorldTransform.v2.x + 216i64) != v8 )
      {
        ComponentOfType = UFG::SimObject::GetComponentOfType(
                            ComponentOfType->m_pSimObject,
                            UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                            0,
                            ComponentOfType);
        if ( !ComponentOfType )
          goto LABEL_15;
      }
      v14 = (UFG::RigidBody *)ComponentOfType;
    }
  }
LABEL_15:
  if ( v16 )
  {
    v21 = v16->m_Flags;
    if ( (v21 & 0x4000) != 0 || v21 < 0 || (v21 & 0x2000) != 0 || (v21 & 0x1000) != 0 )
      v22 = UFG::SimObjectGame::GetComponentOfTypeHK(v16, UFG::RigidBodyComponent::_TypeUID);
    else
      v22 = UFG::SimObject::GetComponentOfType(v16, UFG::RigidBodyComponent::_TypeUID);
    v23 = (UFG::TransformNodeComponent *)v22;
    if ( v22 )
    {
      while ( v17 && *(_DWORD *)(*(_QWORD *)&v23->mWorldTransform.v2.x + 216i64) != v17 )
      {
        v23 = UFG::SimObject::GetComponentOfType(
                v23->m_pSimObject,
                UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                0,
                v23);
        if ( !v23 )
          goto LABEL_29;
      }
      v15 = (UFG::RigidBody *)v23;
    }
  }
LABEL_29:
  if ( v14 )
  {
    LOBYTE(v13) = 1;
    v14->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[15].__vecDelDtor(v14, v13);
    v14->mFlags &= ~1u;
    mBody = v14->mBody;
    if ( v15 )
    {
      LOBYTE(v24) = 1;
      v15->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[15].__vecDelDtor(v15, v24);
      v15->mFlags &= ~1u;
      v12 = v15->mBody;
    }
    if ( mBody )
    {
      v26 = UFG::Constraint::CreateBallAndSocketConstraint(mBody, v12, &name, &pivot);
      UFG::RigidBody::AddConstraint(v14, v26);
      hkpEntity::activate(mBody);
      if ( v15 )
      {
        UFG::RigidBody::AddConstraint(v15, v26);
        hkpEntity::activate(v12);
      }
      UFG::BasePhysicsSystem::AddConstraint(UFG::BasePhysicsSystem::mInstance, v26->mConstraintInstance);
    }
  }
}

// File Line: 257
// RVA: 0x46D4D0
void __fastcall PhysicsSkookum::MthdC_delete_constraint(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObjectGame *ArgByNameOrInstance; // rax
  SSData **i_array_p; // r8
  int i_user_data; // ebx
  unsigned int v6; // edi
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::RigidBody *ComponentOfType; // rsi
  hkpEntity *v10; // rcx
  UFG::Constraint *ConstraintByName; // rax
  UFG::Constraint *v12; // rbx
  __int64 v13; // rdx
  hkpEntity *mBody; // rcx
  UFG::qSymbol name; // [rsp+40h] [rbp+8h] BYREF
  UFG::qSymbol *p_name; // [rsp+50h] [rbp+18h]

  ArgByNameOrInstance = (UFG::SimObjectGame *)UFG::TSSimObject::GetArgByNameOrInstance(pScope, 0);
  i_array_p = pScope->i_data.i_array_p;
  i_user_data = i_array_p[1]->i_data_p->i_user_data;
  v6 = i_array_p[2]->i_data_p->i_user_data;
  if ( ArgByNameOrInstance )
  {
    m_Flags = ArgByNameOrInstance->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                            ArgByNameOrInstance,
                            UFG::RigidBodyComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(ArgByNameOrInstance, UFG::RigidBodyComponent::_TypeUID);
    ComponentOfType = (UFG::RigidBody *)ComponentOfTypeHK;
    if ( ComponentOfTypeHK )
    {
      while ( i_user_data && ComponentOfType->mCollisionMeshData->mName.mUID != i_user_data )
      {
        ComponentOfType = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                              ComponentOfType->m_pSimObject,
                                              UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                                              0,
                                              ComponentOfType);
        if ( !ComponentOfType )
          return;
      }
      if ( ComponentOfType )
      {
        if ( v6 )
        {
          p_name = &name;
          name.mUID = v6;
          ConstraintByName = UFG::RigidBody::GetConstraintByName(ComponentOfType, (int *)&name);
          v12 = ConstraintByName;
          if ( ConstraintByName )
          {
            UFG::BasePhysicsSystem::RemoveConstraint(
              UFG::BasePhysicsSystem::mInstance,
              ConstraintByName->mConstraintInstance);
            UFG::RigidBody::RemoveConstraint(ComponentOfType, v12);
            LOBYTE(v13) = 1;
            ComponentOfType->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[15].__vecDelDtor(
              ComponentOfType,
              v13);
            mBody = ComponentOfType->mBody;
            if ( mBody )
              hkpEntity::activate(mBody);
            v12->vfptr->__vecDelDtor(v12, 1u);
          }
        }
        else
        {
          UFG::RigidBody::DeleteAllConstraints(ComponentOfType);
          v10 = ComponentOfType->mBody;
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
  SSData **i_array_p; // rdx
  float v3; // xmm6_4
  unsigned int mUID; // eax
  UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *p_mNext; // rdx
  UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> *mPrev; // rax
  float v7; // xmm0_4
  UFG::qSymbol result; // [rsp+40h] [rbp+8h] BYREF

  i_array_p = pScope->i_data.i_array_p;
  v3 = *(float *)&i_array_p[1]->i_data_p->i_user_data;
  mUID = UFG::qSymbol::create_from_string(&result, *(const char **)(*i_array_p)->i_data_p->i_user_data)->mUID;
  p_mNext = (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)&UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext;
  if ( &UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext != (UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> **)((char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList - 280) )
  {
    while ( LODWORD(p_mNext[2].mNode.mNext[4].mNext) != mUID )
    {
      p_mNext = (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)&p_mNext[18].mNode.mPrev[-18].mNext;
      if ( p_mNext == (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)((char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList
                                                                                        - 280) )
        return;
    }
    mPrev = p_mNext[24].mNode.mPrev;
    if ( mPrev && v3 > 0.0 && mPrev[9].mNext )
    {
      v7 = *((float *)&mPrev[16].mNext + 1) - v3;
      *((float *)&mPrev[16].mNext + 1) = v7;
      if ( v7 < 0.0 )
        HIDWORD(mPrev[16].mNext) = 0;
    }
  }
}

// File Line: 347
// RVA: 0x46D750
void __fastcall PhysicsSkookum::MthdC_shear_object(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SimObject *ArgByNameOrInstance; // r10
  SSData **i_array_p; // r8
  float *i_user_data; // rcx
  float v6; // xmm1_4
  float v7; // xmm0_4
  SSInstance *i_data_p; // rax
  float *v9; // rcx
  float v10; // xmm1_4
  float v11; // xmm2_4
  UFG::qVector3 v12; // [rsp+20h] [rbp-28h] BYREF
  UFG::qVector3 v13; // [rsp+30h] [rbp-18h] BYREF

  ArgByNameOrInstance = UFG::TSSimObject::GetArgByNameOrInstance(pScope, 0);
  if ( ArgByNameOrInstance )
  {
    i_array_p = pScope->i_data.i_array_p;
    i_user_data = (float *)i_array_p[1]->i_data_p->i_user_data;
    v6 = i_user_data[1];
    v13.x = *i_user_data;
    v7 = i_user_data[2];
    v13.y = v6;
    i_data_p = i_array_p[2]->i_data_p;
    v13.z = v7;
    v9 = (float *)i_data_p->i_user_data;
    v10 = v9[1];
    v11 = v9[2];
    v12.x = *v9;
    v12.y = v10;
    v12.z = v11;
    UFG::ShearObject(ArgByNameOrInstance, &v13, &v12, v9 != 0i64);
  }
}

// File Line: 363
// RVA: 0x46D6D0
void __fastcall PhysicsSkookum::MthdC_enable_fracture(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *p_mNext; // rcx
  UFG::qSymbol result; // [rsp+30h] [rbp+8h] BYREF

  UFG::qSymbol::create_from_string(&result, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  p_mNext = (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)&UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext;
  if ( &UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext != (UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> **)((char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList - 280) )
  {
    while ( LODWORD(p_mNext[2].mNode.mNext[4].mNext) != result.mUID )
    {
      p_mNext = (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)&p_mNext[18].mNode.mPrev[-18].mNext;
      if ( p_mNext == (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)((char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList
                                                                                        - 280) )
        return;
    }
    UFG::RigidBody::EnableFractureParts((UFG::RigidBody *)p_mNext, FRACTURE_STRENGTH_NORMAL);
  }
}

// File Line: 385
// RVA: 0x46D660
void __fastcall PhysicsSkookum::MthdC_disable_fracture(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *p_mNext; // rcx
  UFG::qSymbol result; // [rsp+30h] [rbp+8h] BYREF

  UFG::qSymbol::create_from_string(&result, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  p_mNext = (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)&UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext;
  if ( &UFG::RigidBodyComponent::s_RigidBodyComponentList.mNode.mNext[-18].mNext != (UFG::qNode<UFG::RigidBodyComponent,UFG::RigidBodyComponent> **)((char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList - 280) )
  {
    while ( LODWORD(p_mNext[2].mNode.mNext[4].mNext) != result.mUID )
    {
      p_mNext = (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)&p_mNext[18].mNode.mPrev[-18].mNext;
      if ( p_mNext == (UFG::qList<UFG::RigidBodyComponent,UFG::RigidBodyComponent,1,0> *)((char *)&UFG::RigidBodyComponent::s_RigidBodyComponentList
                                                                                        - 280) )
        return;
    }
    UFG::RigidBody::DisableFractureParts((UFG::RigidBody *)p_mNext);
  }
}

