// File Line: 26
// RVA: 0x3E0080
void __fastcall NISLightGroup::NISLightGroup(NISLightGroup *this, const char *lightGroupName)
{
  const char *v2; // rbp
  NISLightGroup *v3; // r14
  UFG::qString *v4; // rax
  UFG::qString result; // [rsp+38h] [rbp-50h]

  v2 = lightGroupName;
  v3 = this;
  this->mSimObject.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mSimObject.mPrev;
  this->mSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mSimObject.mPrev;
  this->mSimObject.m_pPointer = 0i64;
  this->mValid = 0;
  UFG::qString::qString(&this->mLightGroupName);
  UFG::qString::qString(&v3->mLightGroupFileName);
  v3->mLightRigHandle = 0i64;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v3->mRigResource.mPrev);
  v3->mRigResource.mLoadFunction = 0i64;
  v3->mRigResource.mUnloadFunction = 0i64;
  v3->mRigResource.mUserData = 0i64;
  v3->mRigResource.mUFGSkeleton = 0i64;
  UFG::qString::Set(&v3->mLightGroupName, v2);
  v4 = UFG::qString::FormatEx(&result, "Data\\NIS\\%s_LIGHT.xml", v2);
  UFG::qString::Set(&v3->mLightGroupFileName, v4->mData, v4->mLength, 0i64, 0);
  UFG::qString::~qString(&result);
  v3->mValid = UFG::LightGroupComponent::GroupExists(v3->mLightGroupFileName.mData);
}

// File Line: 34
// RVA: 0x3E09C0
void __fastcall NISLightGroup::~NISLightGroup(NISLightGroup *this)
{
  NISLightGroup *v1; // rbx
  UFG::StreamPriorityHandle *v2; // rdx
  UFG::SimObject *v3; // rdx
  UFG::qResourceInventory *v4; // rax
  UFG::qResourceWarehouse *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax

  v1 = this;
  v2 = this->mLightRigHandle;
  if ( v2 )
  {
    UFG::StreamPrioritySystem::FreeHandle(NISManager::sStreamPrioritySystem, v2);
    v1->mLightRigHandle = 0i64;
  }
  v3 = v1->mSimObject.m_pPointer;
  if ( v3 )
    UFG::Simulation::DestroySimObject(&UFG::gSim, v3);
  v4 = `UFG::qGetResourceInventory<UFG::RigResource>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<UFG::RigResource>'::`2'::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    v4 = UFG::qResourceWarehouse::GetInventory(v5, 0x39BC0A7Eu);
    `UFG::qGetResourceInventory<UFG::RigResource>'::`2'::result = v4;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mRigResource.mPrev, v4);
  UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v1->mRigResource.mPrev);
  UFG::qString::~qString(&v1->mLightGroupFileName);
  UFG::qString::~qString(&v1->mLightGroupName);
  if ( v1->mSimObject.m_pPointer )
  {
    v6 = v1->mSimObject.mPrev;
    v7 = v1->mSimObject.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v1->mSimObject.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mSimObject.mPrev;
    v1->mSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mSimObject.mPrev;
  }
  v1->mSimObject.m_pPointer = 0i64;
  v8 = v1->mSimObject.mPrev;
  v9 = v1->mSimObject.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v1->mSimObject.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mSimObject.mPrev;
  v1->mSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mSimObject.mPrev;
}

// File Line: 57
// RVA: 0x3E3F50
void __fastcall NISLightGroup::PreLoadResource(NISLightGroup *this)
{
  NISLightGroup *v1; // rbx
  UFG::StreamPriorityHandle *v2; // rax
  UFG::qSharedString filename; // [rsp+40h] [rbp+8h]

  v1 = this;
  if ( this->mValid )
  {
    UFG::qSharedString::qSharedString(
      &filename,
      "Data\\AnimationNIS\\LightRigs\\%s_LIGHTRIG.BIN",
      this->mLightGroupName.mData);
    v2 = UFG::StreamPrioritySystem::CreateHandle(NISManager::sStreamPrioritySystem, &filename);
    v1->mLightRigHandle = v2;
    UFG::StreamPrioritySystem::ChangePriority(NISManager::sStreamPrioritySystem, v2, 0x100000u);
    UFG::qSharedString::~qSharedString(&filename);
  }
}

// File Line: 67
// RVA: 0x3E3920
void __fastcall NISLightGroup::Play(NISLightGroup *this)
{
  NISLightGroup *v1; // rdi
  int v2; // edx
  unsigned int v3; // ebx
  UFG::qResourceInventory *v4; // rax
  UFG::qResourceWarehouse *v5; // rax
  UFG::SimObject *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::LightGroupComponent *v11; // rbx
  UFG::SimObject *v12; // rcx
  UFG::LightGroupComponent *v13; // rax
  UFG::LightGroupAnimationComponent *v14; // rbx
  UFG::SimObjectModifier v15; // [rsp+28h] [rbp-50h]
  UFG::qString result; // [rsp+48h] [rbp-30h]
  UFG::qSymbol name_a; // [rsp+88h] [rbp+10h]
  UFG::qSymbol name; // [rsp+90h] [rbp+18h]

  v1 = this;
  if ( this->mValid )
  {
    UFG::qString::FormatEx(&result, "%s_LIGHTRIG", this->mLightGroupName.mData);
    v3 = result.mStringHash32;
    if ( result.mStringHash32 == -1 )
    {
      v3 = UFG::qStringHash32(result.mData, result.mStringHash32 | v2);
      result.mStringHash32 = v3;
    }
    v4 = `UFG::qGetResourceInventory<UFG::RigResource>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<UFG::RigResource>'::`2'::result )
    {
      v5 = UFG::qResourceWarehouse::Instance();
      v4 = UFG::qResourceWarehouse::GetInventory(v5, 0x39BC0A7Eu);
      `UFG::qGetResourceInventory<UFG::RigResource>'::`2'::result = v4;
    }
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v1->mRigResource.mPrev, 0x39BC0A7Eu, v3, v4);
    if ( v1->mRigResource.mData )
    {
      if ( !v1->mSimObject.m_pPointer )
      {
        name_a.mUID = -1;
        UFG::qSymbol::set_from_cstr(&name_a, v1->mLightGroupName.mData);
        UFG::qSymbol::create_suffix(&name, &name_a, "_LIGHT");
        v6 = UFG::Simulation::CreateSimObject(&UFG::gSim, &name);
        if ( v1->mSimObject.m_pPointer )
        {
          v7 = v1->mSimObject.mPrev;
          v8 = v1->mSimObject.mNext;
          v7->mNext = v8;
          v8->mPrev = v7;
          v1->mSimObject.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mSimObject.mPrev;
          v1->mSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mSimObject.mPrev;
        }
        v1->mSimObject.m_pPointer = v6;
        if ( v6 )
        {
          v9 = &v6->m_SafePointerList.mNode;
          v10 = v6->m_SafePointerList.mNode.mPrev;
          v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mSimObject.mPrev;
          v1->mSimObject.mPrev = v10;
          v1->mSimObject.mNext = v9;
          v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mSimObject.mPrev;
        }
        v11 = UFG::LightGroupComponent::Init(v1->mLightGroupFileName.mData);
        UFG::SimObjectModifier::SimObjectModifier(&v15, v1->mSimObject.m_pPointer, 1);
        UFG::SimObjectModifier::AttachComponent(&v15, (UFG::SimComponent *)&v11->vfptr, 0xFFFFFFFFi64);
        UFG::SimObjectModifier::Close(&v15);
        UFG::SimObjectModifier::~SimObjectModifier(&v15);
      }
      v12 = v1->mSimObject.m_pPointer;
      if ( v12 )
      {
        v13 = (UFG::LightGroupComponent *)UFG::SimObject::GetComponentOfType(v12, UFG::LightGroupComponent::_TypeUID);
        if ( v13 )
          UFG::LightGroupComponent::AttachLights(v13);
        v14 = UFG::LightGroupAnimationComponent::Init((UFG::RigResource *)v1->mRigResource.mData);
        UFG::SimObjectModifier::SimObjectModifier(&v15, v1->mSimObject.m_pPointer, 1);
        UFG::SimObjectModifier::AttachComponent(&v15, (UFG::SimComponent *)&v14->vfptr, 0xFFFFFFFFi64);
        UFG::SimObjectModifier::Close(&v15);
        UFG::SimObjectModifier::~SimObjectModifier(&v15);
        if ( v14 )
          v14->mUpdatedFromNIS = 1;
      }
    }
    UFG::qString::~qString(&result);
  }
}

