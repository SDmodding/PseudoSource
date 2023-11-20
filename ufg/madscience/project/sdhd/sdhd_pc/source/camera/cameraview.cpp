// File Line: 171
// RVA: 0x3C5D30
void __fastcall UFG::InitCameraView(UFG *this)
{
  UFG::bCameraTweakersAdded = 1;
}

// File Line: 259
// RVA: 0x3C2BD0
UFG::BaseCameraComponent *__fastcall UFG::GetCurrentBaseCamera()
{
  return UFG::Director::Get()->mCurrentCamera;
}

// File Line: 262
// RVA: 0x3C2BF0
UFG::SimComponent *__fastcall UFG::GetCurrentGameCamera()
{
  UFG::SimComponent *v0; // r14
  UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *v1; // rbx
  UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *v2; // rsi
  UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *v3; // r15
  UFG::qList<UFG::BaseCameraComponent,UFG::BaseCameraComponent,1,0> *v4; // rdi
  UFG::BaseCameraComponent *v5; // rax
  UFG::SimObject *v6; // rax
  UFG::SimObject *v8; // rcx

  v0 = 0i64;
  v1 = UFG::BaseCameraComponent::s_BaseCameraComponentList.mNode.mNext - 4;
  v2 = 0i64;
  if ( (UFG::qList<UFG::BaseCameraComponent,UFG::BaseCameraComponent,1,0> *)&UFG::BaseCameraComponent::s_BaseCameraComponentList.mNode.mNext[-4] != &UFG::BaseCameraComponent::s_BaseCameraComponentList - 4 )
  {
    do
    {
      v3 = v1[2].mNext;
      v4 = (UFG::qList<UFG::BaseCameraComponent,UFG::BaseCameraComponent,1,0> *)&v1[4].mNext[-4];
      v5 = UFG::Director::Get()->mCurrentCamera;
      if ( v5 )
        v6 = v5->m_pSimObject;
      else
        v6 = 0i64;
      if ( v3 == (UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *)v6
        && BYTE1(v1[43].mPrev)
        && UFG::SimComponent::IsType((UFG::SimComponent *)v1, UFG::GameCameraComponent::_GameCameraComponentTypeUID) )
      {
        v2 = v1;
      }
      v1 = &v4->mNode;
    }
    while ( v4 != &UFG::BaseCameraComponent::s_BaseCameraComponentList - 4 );
    if ( v2 )
      return (UFG::SimComponent *)v2;
  }
  v8 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v8 )
    v0 = UFG::SimObject::GetComponentOfType(v8, UFG::GameCameraComponent::_TypeUID);
  return v0;
}

// File Line: 289
// RVA: 0x3C5F10
bool __fastcall UFG::IsCameraUsingHighZoom()
{
  UFG::SimComponent *v0; // rax

  v0 = UFG::GetCurrentGameCamera();
  return v0 && ((unsigned __int8 (__fastcall *)(UFG::SimComponent *))v0->vfptr[36].__vecDelDtor)(v0);
}

// File Line: 416
// RVA: 0x3BF330
void __fastcall UFG::AttachCameraToView(UFG::BaseCameraComponent *cc)
{
  UFG::BaseCameraComponent *v1; // rbx
  UFG::Director *v2; // rax

  v1 = cc;
  v2 = UFG::Director::Get();
  UFG::Director::SetCurrentCamera(v2, v1);
}

// File Line: 419
// RVA: 0x3C1830
void __fastcall UFG::CreateDirector(UFG *this)
{
  UFG::SimObject *v1; // rax
  UFG::qSymbol parentSetName; // [rsp+40h] [rbp+8h]
  UFG::qSymbol result; // [rsp+48h] [rbp+10h]

  if ( !UFG::Director::Get() )
  {
    UFG::qSymbol::create_from_string(&result, "CameraDirector");
    UFG::qSymbol::create_from_string(&parentSetName, "object-logical-Director");
    v1 = UFG::SpawnInfoInterface::SpawnObject(&result, &parentSetName, 0, 0i64, 0i64, 0i64);
    if ( v1 )
      UFG::SimObject::GetComponentOfType(v1, UFG::Director::_TypeUID);
  }
}

// File Line: 436
// RVA: 0x3C16E0
void __fastcall UFG::CreateCameraObjects(UFG *this)
{
  UFG::DebugCameraComponent *v1; // rbx
  UFG::SimObject *v2; // rax
  UFG::BaseCameraComponent *v3; // rdi
  UFG::Director *v4; // rax
  UFG::qSymbol *v5; // rax
  UFG::SimObject *v6; // rsi
  UFG::qMemoryPool *v7; // rax
  UFG::allocator::free_link *v8; // rdi
  unsigned int v9; // eax
  UFG::DebugCameraComponent *v10; // rax
  UFG::SimObjectModifier v11; // [rsp+38h] [rbp-40h]
  UFG::qSymbol parentSetName; // [rsp+80h] [rbp+8h]
  UFG::qSymbol result; // [rsp+88h] [rbp+10h]
  UFG::qSymbol v14; // [rsp+90h] [rbp+18h]
  UFG::allocator::free_link *v15; // [rsp+98h] [rbp+20h]

  UFG::CreateDirector(this);
  UFG::qSymbol::create_from_string(&result, "FollowCameraWalk");
  UFG::qSymbol::create_from_string(&parentSetName, "object-logical-Camera");
  v1 = 0i64;
  v2 = UFG::SpawnInfoInterface::SpawnObject(&result, &parentSetName, 0, 0i64, 0i64, 0i64);
  if ( v2 )
    v3 = (UFG::BaseCameraComponent *)UFG::SimObject::GetComponentOfType(v2, UFG::FollowCameraComponent::_TypeUID);
  else
    v3 = 0i64;
  v4 = UFG::Director::Get();
  UFG::Director::SetCurrentCamera(v4, v3);
  v5 = UFG::qSymbol::create_from_string(&v14, "DebugCamera1");
  v6 = UFG::Simulation::CreateSimObject(&UFG::gSim, v5);
  v7 = UFG::GetSimulationMemoryPool();
  v8 = UFG::qMemoryPool::Allocate(v7, 0x350ui64, "DebugCameraComponent", 0i64, 1u);
  v15 = v8;
  if ( v8 )
  {
    v9 = UFG::qStringHash32("DebugCamera", 0xFFFFFFFF);
    UFG::DebugCameraComponent::DebugCameraComponent((UFG::DebugCameraComponent *)v8, v9);
    v1 = v10;
  }
  UFG::gDebugCameraComponent = v1;
  UFG::SimObjectModifier::SimObjectModifier(&v11, v6, 1);
  UFG::SimObjectModifier::AttachComponent(&v11, (UFG::SimComponent *)&UFG::gDebugCameraComponent->vfptr, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v11);
  UFG::SimObjectModifier::~SimObjectModifier(&v11);
}

// File Line: 452
// RVA: 0x3C8AE0
void __fastcall UFG::ResetCameraObjects(UFG::SimObject *target)
{
  UFG::SimObject *v1; // rdi
  UFG::SimObject *v2; // rcx
  UFG::SimComponent *v3; // rax
  UFG::SimObject *v4; // rcx
  UFG::SimComponent *v5; // rax
  UFG::BaseCameraComponent *v6; // rbx
  UFG::Director *v7; // rax
  UFG::SimObject *v8; // rcx
  UFG::CharacterSubjectComponent *v9; // rbx
  UFG::qSymbol v10; // eax
  UFG::qSymbol v11; // eax
  UFG::qSymbol v12; // eax
  UFG::qSymbol v13; // eax
  UFG::qSymbol v14; // eax
  UFG::qSymbol v15; // eax
  UFG::qSymbol v16; // eax
  UFG::qSymbol v17; // eax
  UFG::qWiseSymbol result; // [rsp+48h] [rbp+18h]
  UFG::qWiseSymbol *v19; // [rsp+50h] [rbp+20h]

  v1 = target;
  v2 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v2 )
  {
    v3 = UFG::SimObject::GetComponentOfType(v2, UFG::ChaseCameraComponent::_TypeUID);
    if ( v3 )
      v3->vfptr[16].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v3->vfptr, (unsigned int)v1);
  }
  v4 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v4 )
  {
    v5 = UFG::SimObject::GetComponentOfType(v4, UFG::FollowCameraComponent::_TypeUID);
    v6 = (UFG::BaseCameraComponent *)v5;
    if ( v5 )
    {
      v5->vfptr[16].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v5->vfptr, (unsigned int)v1);
      v7 = UFG::Director::Get();
      UFG::Director::SetCurrentCamera(v7, v6);
      v8 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
      if ( v8 )
      {
        v9 = (UFG::CharacterSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                 v8,
                                                 UFG::CharacterSubjectComponent::_TypeUID);
        if ( v9 )
        {
          v19 = &result;
          v10.mUID = (unsigned int)UFG::qSymbol::qSymbol(&result, 0xFFFFFFFF);
          UFG::CharacterSubjectComponent::SetContextOverrideScriptGlobal(v9, 0, v10);
          v19 = &result;
          v11.mUID = (unsigned int)UFG::qSymbol::qSymbol(&result, 0xFFFFFFFF);
          UFG::CharacterSubjectComponent::SetContextOverrideScriptGlobal(v9, 1, v11);
          v19 = &result;
          v12.mUID = (unsigned int)UFG::qSymbol::qSymbol(&result, 0xFFFFFFFF);
          UFG::CharacterSubjectComponent::SetContextOverrideScriptGlobal(v9, 2, v12);
          v19 = &result;
          v13.mUID = (unsigned int)UFG::qSymbol::qSymbol(&result, 0xFFFFFFFF);
          UFG::CharacterSubjectComponent::SetContextOverrideScriptGlobal(v9, 3, v13);
          v19 = &result;
          v14.mUID = (unsigned int)UFG::qSymbol::qSymbol(&result, 0xFFFFFFFF);
          UFG::CharacterSubjectComponent::SetContextOverrideScriptLocal(v9, 0, v14);
          v19 = &result;
          v15.mUID = (unsigned int)UFG::qSymbol::qSymbol(&result, 0xFFFFFFFF);
          UFG::CharacterSubjectComponent::SetContextOverrideScriptLocal(v9, 1, v15);
          v19 = &result;
          v16.mUID = (unsigned int)UFG::qSymbol::qSymbol(&result, 0xFFFFFFFF);
          UFG::CharacterSubjectComponent::SetContextOverrideScriptLocal(v9, 2, v16);
          v19 = &result;
          v17.mUID = (unsigned int)UFG::qSymbol::qSymbol(&result, 0xFFFFFFFF);
          UFG::CharacterSubjectComponent::SetContextOverrideScriptLocal(v9, 3, v17);
        }
      }
    }
  }
}

