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
UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *__fastcall UFG::GetCurrentGameCamera()
{
  __int64 v0; // r14
  UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *p_mNode; // rbx
  UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *v2; // rsi
  UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *mNext; // r15
  UFG::qList<UFG::BaseCameraComponent,UFG::BaseCameraComponent,1,0> *v4; // rdi
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  UFG::SimObject *m_pSimObject; // rax
  UFG::SimObject *v8; // rcx

  v0 = 0i64;
  p_mNode = UFG::BaseCameraComponent::s_BaseCameraComponentList.mNode.mNext - 4;
  v2 = 0i64;
  if ( (UFG::qList<UFG::BaseCameraComponent,UFG::BaseCameraComponent,1,0> *)&UFG::BaseCameraComponent::s_BaseCameraComponentList.mNode.mNext[-4] != &UFG::BaseCameraComponent::s_BaseCameraComponentList - 4 )
  {
    do
    {
      mNext = p_mNode[2].mNext;
      v4 = (UFG::qList<UFG::BaseCameraComponent,UFG::BaseCameraComponent,1,0> *)&p_mNode[4].mNext[-4];
      mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
      if ( mCurrentCamera )
        m_pSimObject = mCurrentCamera->m_pSimObject;
      else
        m_pSimObject = 0i64;
      if ( mNext == (UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *)m_pSimObject
        && BYTE1(p_mNode[43].mPrev)
        && UFG::SimComponent::IsType(
             (UFG::SimComponent *)p_mNode,
             UFG::GameCameraComponent::_GameCameraComponentTypeUID) )
      {
        v2 = p_mNode;
      }
      p_mNode = &v4->mNode;
    }
    while ( v4 != &UFG::BaseCameraComponent::s_BaseCameraComponentList - 4 );
    if ( v2 )
      return v2;
  }
  v8 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v8 )
    return (UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *)UFG::SimObject::GetComponentOfType(
                                                                              v8,
                                                                              UFG::GameCameraComponent::_TypeUID);
  return (UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *)v0;
}

// File Line: 289
// RVA: 0x3C5F10
bool __fastcall UFG::IsCameraUsingHighZoom()
{
  UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *CurrentGameCamera; // rax

  CurrentGameCamera = UFG::GetCurrentGameCamera();
  return CurrentGameCamera
      && ((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::BaseCameraComponent,UFG::BaseCameraComponent> *))CurrentGameCamera->mPrev[18].mPrev)(CurrentGameCamera);
}

// File Line: 416
// RVA: 0x3BF330
void __fastcall UFG::AttachCameraToView(UFG::BaseCameraComponent *cc)
{
  UFG::Director *v2; // rax

  v2 = UFG::Director::Get();
  UFG::Director::SetCurrentCamera(v2, cc);
}

// File Line: 419
// RVA: 0x3C1830
void __fastcall UFG::CreateDirector(UFG *this)
{
  UFG::SimObject *v1; // rax
  UFG::qSymbol parentSetName; // [rsp+40h] [rbp+8h] BYREF
  UFG::qSymbol result; // [rsp+48h] [rbp+10h] BYREF

  if ( !UFG::Director::Get() )
  {
    UFG::qSymbol::create_from_string(&result, "CameraDirector");
    UFG::qSymbol::create_from_string(&parentSetName, "object-logical-Director");
    v1 = UFG::SpawnInfoInterface::SpawnObject(&result, &parentSetName, UnReferenced, 0i64, 0i64, 0i64);
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
  UFG::BaseCameraComponent *ComponentOfType; // rdi
  UFG::Director *v4; // rax
  UFG::qSymbol *v5; // rax
  UFG::SimObject *SimObject; // rsi
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v8; // rdi
  unsigned int v9; // eax
  UFG::DebugCameraComponent *v10; // rax
  UFG::SimObjectModifier v11; // [rsp+38h] [rbp-40h] BYREF
  UFG::qSymbol parentSetName; // [rsp+80h] [rbp+8h] BYREF
  UFG::qSymbol result; // [rsp+88h] [rbp+10h] BYREF
  UFG::qSymbol v14; // [rsp+90h] [rbp+18h] BYREF
  UFG::allocator::free_link *v15; // [rsp+98h] [rbp+20h]

  UFG::CreateDirector(this);
  UFG::qSymbol::create_from_string(&result, "FollowCameraWalk");
  UFG::qSymbol::create_from_string(&parentSetName, "object-logical-Camera");
  v1 = 0i64;
  v2 = UFG::SpawnInfoInterface::SpawnObject(&result, &parentSetName, UnReferenced, 0i64, 0i64, 0i64);
  if ( v2 )
    ComponentOfType = (UFG::BaseCameraComponent *)UFG::SimObject::GetComponentOfType(
                                                    v2,
                                                    UFG::FollowCameraComponent::_TypeUID);
  else
    ComponentOfType = 0i64;
  v4 = UFG::Director::Get();
  UFG::Director::SetCurrentCamera(v4, ComponentOfType);
  v5 = UFG::qSymbol::create_from_string(&v14, "DebugCamera1");
  SimObject = UFG::Simulation::CreateSimObject(&UFG::gSim, v5);
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v8 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x350ui64, "DebugCameraComponent", 0i64, 1u);
  v15 = v8;
  if ( v8 )
  {
    v9 = UFG::qStringHash32("DebugCamera", 0xFFFFFFFF);
    UFG::DebugCameraComponent::DebugCameraComponent((UFG::DebugCameraComponent *)v8, v9);
    v1 = v10;
  }
  UFG::gDebugCameraComponent = v1;
  UFG::SimObjectModifier::SimObjectModifier(&v11, SimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v11, UFG::gDebugCameraComponent, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v11);
  UFG::SimObjectModifier::~SimObjectModifier(&v11);
}

// File Line: 452
// RVA: 0x3C8AE0
void __fastcall UFG::ResetCameraObjects(UFG::SimObject *target)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimObject *v4; // rcx
  UFG::SimComponent *v5; // rax
  UFG::BaseCameraComponent *v6; // rbx
  UFG::Director *v7; // rax
  UFG::SimObject *v8; // rcx
  UFG::CharacterSubjectComponent *v9; // rbx
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // eax
  unsigned int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // eax
  UFG::qWiseSymbol result; // [rsp+48h] [rbp+18h] BYREF
  UFG::qWiseSymbol *p_result; // [rsp+50h] [rbp+20h]

  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::ChaseCameraComponent::_TypeUID);
    if ( ComponentOfType )
      ComponentOfType->vfptr[16].__vecDelDtor(ComponentOfType, (unsigned int)target);
  }
  v4 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v4 )
  {
    v5 = UFG::SimObject::GetComponentOfType(v4, UFG::FollowCameraComponent::_TypeUID);
    v6 = (UFG::BaseCameraComponent *)v5;
    if ( v5 )
    {
      v5->vfptr[16].__vecDelDtor(v5, (unsigned int)target);
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
          p_result = &result;
          v10 = (unsigned int)UFG::qSymbol::qSymbol(&result, 0xFFFFFFFF);
          UFG::CharacterSubjectComponent::SetContextOverrideScriptGlobal(v9, 0, (UFG::qSymbol)v10);
          p_result = &result;
          v11 = (unsigned int)UFG::qSymbol::qSymbol(&result, 0xFFFFFFFF);
          UFG::CharacterSubjectComponent::SetContextOverrideScriptGlobal(v9, 1, (UFG::qSymbol)v11);
          p_result = &result;
          v12 = (unsigned int)UFG::qSymbol::qSymbol(&result, 0xFFFFFFFF);
          UFG::CharacterSubjectComponent::SetContextOverrideScriptGlobal(v9, 2, (UFG::qSymbol)v12);
          p_result = &result;
          v13 = (unsigned int)UFG::qSymbol::qSymbol(&result, 0xFFFFFFFF);
          UFG::CharacterSubjectComponent::SetContextOverrideScriptGlobal(v9, 3, (UFG::qSymbol)v13);
          p_result = &result;
          v14 = (unsigned int)UFG::qSymbol::qSymbol(&result, 0xFFFFFFFF);
          UFG::CharacterSubjectComponent::SetContextOverrideScriptLocal(v9, 0, (UFG::qSymbol)v14);
          p_result = &result;
          v15 = (unsigned int)UFG::qSymbol::qSymbol(&result, 0xFFFFFFFF);
          UFG::CharacterSubjectComponent::SetContextOverrideScriptLocal(v9, 1, (UFG::qSymbol)v15);
          p_result = &result;
          v16 = (unsigned int)UFG::qSymbol::qSymbol(&result, 0xFFFFFFFF);
          UFG::CharacterSubjectComponent::SetContextOverrideScriptLocal(v9, 2, (UFG::qSymbol)v16);
          p_result = &result;
          v17 = (unsigned int)UFG::qSymbol::qSymbol(&result, 0xFFFFFFFF);
          UFG::CharacterSubjectComponent::SetContextOverrideScriptLocal(v9, 3, (UFG::qSymbol)v17);
        }
      }
    }
  }
}

