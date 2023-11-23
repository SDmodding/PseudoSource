// File Line: 26
// RVA: 0x3E0080
void __fastcall NISLightGroup::NISLightGroup(NISLightGroup *this, const char *lightGroupName)
{
  UFG::qString *v4; // rax
  UFG::qString result; // [rsp+38h] [rbp-50h] BYREF

  this->mSimObject.mPrev = &this->mSimObject;
  this->mSimObject.mNext = &this->mSimObject;
  this->mSimObject.m_pPointer = 0i64;
  this->mValid = 0;
  UFG::qString::qString(&this->mLightGroupName);
  UFG::qString::qString(&this->mLightGroupFileName);
  this->mLightRigHandle = 0i64;
  UFG::qResourceHandle::qResourceHandle(&this->mRigResource);
  this->mRigResource.mLoadFunction = 0i64;
  this->mRigResource.mUnloadFunction = 0i64;
  this->mRigResource.mUserData = 0i64;
  this->mRigResource.mUFGSkeleton = 0i64;
  UFG::qString::Set(&this->mLightGroupName, lightGroupName);
  v4 = UFG::qString::FormatEx(&result, "Data\\NIS\\%s_LIGHT.xml", lightGroupName);
  UFG::qString::Set(&this->mLightGroupFileName, v4->mData, v4->mLength, 0i64, 0);
  UFG::qString::~qString(&result);
  this->mValid = UFG::LightGroupComponent::GroupExists(this->mLightGroupFileName.mData);
}

// File Line: 34
// RVA: 0x3E09C0
void __fastcall NISLightGroup::~NISLightGroup(NISLightGroup *this)
{
  UFG::StreamPriorityHandle *mLightRigHandle; // rdx
  UFG::SimObject *m_pPointer; // rdx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax

  mLightRigHandle = this->mLightRigHandle;
  if ( mLightRigHandle )
  {
    UFG::StreamPrioritySystem::FreeHandle(NISManager::sStreamPrioritySystem, mLightRigHandle);
    this->mLightRigHandle = 0i64;
  }
  m_pPointer = this->mSimObject.m_pPointer;
  if ( m_pPointer )
    UFG::Simulation::DestroySimObject(&UFG::gSim, m_pPointer);
  Inventory = `UFG::qGetResourceInventory<UFG::RigResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::RigResource>::`2::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v5, 0x39BC0A7Eu);
    `UFG::qGetResourceInventory<UFG::RigResource>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(&this->mRigResource, Inventory);
  UFG::qResourceHandle::~qResourceHandle(&this->mRigResource);
  UFG::qString::~qString(&this->mLightGroupFileName);
  UFG::qString::~qString(&this->mLightGroupName);
  if ( this->mSimObject.m_pPointer )
  {
    mPrev = this->mSimObject.mPrev;
    mNext = this->mSimObject.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mSimObject.mPrev = &this->mSimObject;
    this->mSimObject.mNext = &this->mSimObject;
  }
  this->mSimObject.m_pPointer = 0i64;
  v8 = this->mSimObject.mPrev;
  v9 = this->mSimObject.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  this->mSimObject.mPrev = &this->mSimObject;
  this->mSimObject.mNext = &this->mSimObject;
}

// File Line: 57
// RVA: 0x3E3F50
void __fastcall NISLightGroup::PreLoadResource(NISLightGroup *this)
{
  UFG::StreamPriorityHandle *v2; // rax
  UFG::qSharedString filename; // [rsp+40h] [rbp+8h] BYREF

  if ( this->mValid )
  {
    UFG::qSharedString::qSharedString(
      &filename,
      "Data\\AnimationNIS\\LightRigs\\%s_LIGHTRIG.BIN",
      this->mLightGroupName.mData);
    v2 = UFG::StreamPrioritySystem::CreateHandle(NISManager::sStreamPrioritySystem, &filename);
    this->mLightRigHandle = v2;
    UFG::StreamPrioritySystem::ChangePriority(NISManager::sStreamPrioritySystem, (UFG::qPropertySet *)v2, 0x100000u);
    UFG::qSharedString::~qSharedString(&filename);
  }
}

// File Line: 67
// RVA: 0x3E3920
void __fastcall NISLightGroup::Play(NISLightGroup *this)
{
  unsigned int mStringHash32; // ebx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v4; // rax
  UFG::SimObject *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *p_mNode; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::LightGroupComponent *v10; // rbx
  UFG::SimObject *m_pPointer; // rcx
  UFG::LightGroupComponent *ComponentOfType; // rax
  UFG::LightGroupAnimationComponent *v13; // rbx
  UFG::SimObjectModifier v14; // [rsp+28h] [rbp-50h] BYREF
  UFG::qString result; // [rsp+48h] [rbp-30h] BYREF
  UFG::qSymbol name_a; // [rsp+88h] [rbp+10h] BYREF
  UFG::qSymbol name; // [rsp+90h] [rbp+18h] BYREF

  if ( this->mValid )
  {
    UFG::qString::FormatEx(&result, "%s_LIGHTRIG", this->mLightGroupName.mData);
    mStringHash32 = result.mStringHash32;
    if ( result.mStringHash32 == -1 )
    {
      mStringHash32 = UFG::qStringHash32(result.mData, 0xFFFFFFFF);
      result.mStringHash32 = mStringHash32;
    }
    Inventory = `UFG::qGetResourceInventory<UFG::RigResource>::`2::result;
    if ( !`UFG::qGetResourceInventory<UFG::RigResource>::`2::result )
    {
      v4 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v4, 0x39BC0A7Eu);
      `UFG::qGetResourceInventory<UFG::RigResource>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Init(&this->mRigResource, 0x39BC0A7Eu, mStringHash32, Inventory);
    if ( this->mRigResource.mData )
    {
      if ( !this->mSimObject.m_pPointer )
      {
        name_a.mUID = -1;
        UFG::qSymbol::set_from_cstr(&name_a, this->mLightGroupName.mData);
        UFG::qSymbol::create_suffix((UFG::qWiseSymbol *)&name, &name_a, "_LIGHT");
        v5 = UFG::Simulation::CreateSimObject(&UFG::gSim, &name);
        if ( this->mSimObject.m_pPointer )
        {
          mPrev = this->mSimObject.mPrev;
          mNext = this->mSimObject.mNext;
          mPrev->mNext = mNext;
          mNext->mPrev = mPrev;
          this->mSimObject.mPrev = &this->mSimObject;
          this->mSimObject.mNext = &this->mSimObject;
        }
        this->mSimObject.m_pPointer = v5;
        if ( v5 )
        {
          p_mNode = &v5->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
          v9 = v5->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
          v9->mNext = &this->mSimObject;
          this->mSimObject.mPrev = v9;
          this->mSimObject.mNext = p_mNode;
          p_mNode->mPrev = &this->mSimObject;
        }
        v10 = UFG::LightGroupComponent::Init(this->mLightGroupFileName.mData);
        UFG::SimObjectModifier::SimObjectModifier(&v14, this->mSimObject.m_pPointer, 1);
        UFG::SimObjectModifier::AttachComponent(&v14, v10, 0xFFFFFFFFi64);
        UFG::SimObjectModifier::Close(&v14);
        UFG::SimObjectModifier::~SimObjectModifier(&v14);
      }
      m_pPointer = this->mSimObject.m_pPointer;
      if ( m_pPointer )
      {
        ComponentOfType = (UFG::LightGroupComponent *)UFG::SimObject::GetComponentOfType(
                                                        m_pPointer,
                                                        UFG::LightGroupComponent::_TypeUID);
        if ( ComponentOfType )
          UFG::LightGroupComponent::AttachLights(ComponentOfType);
        v13 = UFG::LightGroupAnimationComponent::Init((UFG::RigResource *)this->mRigResource.mData);
        UFG::SimObjectModifier::SimObjectModifier(&v14, this->mSimObject.m_pPointer, 1);
        UFG::SimObjectModifier::AttachComponent(&v14, v13, 0xFFFFFFFFi64);
        UFG::SimObjectModifier::Close(&v14);
        UFG::SimObjectModifier::~SimObjectModifier(&v14);
        if ( v13 )
          v13->mUpdatedFromNIS = 1;
      }
    }
    UFG::qString::~qString(&result);
  }
}

