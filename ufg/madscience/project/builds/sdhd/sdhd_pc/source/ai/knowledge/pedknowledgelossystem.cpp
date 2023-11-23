// File Line: 21
// RVA: 0x331440
void __fastcall UFG::PedKnowledgeLOSSystem::PedKnowledgeLOSSystem(UFG::PedKnowledgeLOSSystem *this)
{
  `eh vector constructor iterator(
    this->m_aLOSData.p,
    0x40ui64,
    200,
    (void (__fastcall *)(void *))UFG::PedKnowledgeLOSData::PedKnowledgeLOSData);
  this->m_aLOSData.size = 0;
  this->m_uMaxLOSTestsPerFrame = 10;
}

// File Line: 32
// RVA: 0x33A2D0
void __fastcall UFG::PedKnowledgeLOSSystem::~PedKnowledgeLOSSystem(UFG::PedKnowledgeLOSSystem *this)
{
  this->m_aLOSData.size = 0;
  `eh vector destructor iterator(
    this->m_aLOSData.p,
    0x40ui64,
    200,
    (void (__fastcall *)(void *))UFG::PedKnowledgeLOSData::~PedKnowledgeLOSData);
}

// File Line: 38
// RVA: 0x3848F0
void __fastcall UFG::PedKnowledgeLOSSystem::SendOffASyncRaycastRequests(UFG::PedKnowledgeLOSSystem *this)
{
  unsigned int i; // edi
  unsigned __int64 v3; // rbx
  UFG::SimObjectCVBase *v4; // rcx
  UFG::SimObjectCVBase *v5; // rcx
  UFG::SimComponent *v6; // rdx
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax
  __int64 *v9; // rcx
  __int64 **v10; // rax
  __int64 *mPrev; // rax
  __int64 *v12; // rcx
  __int64 **v13; // rax
  __int64 *v14; // rcx
  __int64 **v15; // rax
  __int64 *v16; // [rsp+120h] [rbp+20h] BYREF
  __int64 **p_m_SafePointerList; // [rsp+128h] [rbp+28h]
  UFG::SimComponent *v18; // [rsp+130h] [rbp+30h]
  void *v19; // [rsp+138h] [rbp+38h]
  void (__fastcall *v20)(UFG::RayCastData *, UFG::SimComponent *, void *); // [rsp+140h] [rbp+40h]
  UFG::qVector3 v21; // [rsp+150h] [rbp+50h] BYREF
  UFG::qVector3 raycastPosition; // [rsp+160h] [rbp+60h] BYREF
  __int64 v23; // [rsp+170h] [rbp+70h]

  v23 = -2i64;
  for ( i = 0; i < this->m_aLOSData.size; ++i )
  {
    v3 = (unsigned __int64)i << 6;
    v4 = *(UFG::SimObjectCVBase **)((char *)&this->m_aLOSData.p[0].pInitiatorSimObject.m_pPointer + v3);
    if ( v4 && *(UFG::SimObject **)((char *)&this->m_aLOSData.p[0].pTargetSimObject.m_pPointer + v3) )
    {
      UFG::ComputeObjectRaycastPosition(v4, &raycastPosition);
      UFG::ComputeObjectRaycastPosition(
        *(UFG::SimObjectCVBase **)((char *)&this->m_aLOSData.p[0].pTargetSimObject.m_pPointer + v3),
        &v21);
      v16 = (__int64 *)&v16;
      p_m_SafePointerList = &v16;
      v18 = 0i64;
      v20 = 0i64;
      v19 = (void *)i;
      v5 = *(UFG::SimObjectCVBase **)((char *)&this->m_aLOSData.p[0].pInitiatorSimObject.m_pPointer + v3);
      if ( v5 )
      {
        m_Flags = v5->m_Flags;
        if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
        {
          ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v5);
        }
        else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        {
          ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                v5,
                                                                UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else
        {
          ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                                v5,
                                                                UFG::ActiveAIEntityComponent::_TypeUID);
        }
        v6 = ComponentOfTypeHK;
      }
      else
      {
        v6 = 0i64;
      }
      if ( v18 )
      {
        v9 = v16;
        v10 = p_m_SafePointerList;
        v16[1] = (__int64)p_m_SafePointerList;
        *v10 = v9;
        v16 = (__int64 *)&v16;
        p_m_SafePointerList = &v16;
      }
      v18 = v6;
      if ( v6 )
      {
        mPrev = (__int64 *)v6->m_SafePointerList.mNode.mPrev;
        mPrev[1] = (__int64)&v16;
        v16 = mPrev;
        p_m_SafePointerList = (__int64 **)&v6->m_SafePointerList;
        v6->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v16;
        v6 = v18;
      }
      v20 = UFG::PedKnowledgeLOSSystem::AsyncRaycastCallback;
      UFG::BasePhysicsSystem::mInstance->vfptr->CastAsyncRay(
        UFG::BasePhysicsSystem::mInstance,
        &raycastPosition,
        &v21,
        0xCu,
        UFG::PedKnowledgeLOSSystem::AsyncRaycastCallback,
        v6,
        v19);
      if ( v18 )
      {
        v12 = v16;
        v13 = p_m_SafePointerList;
        v16[1] = (__int64)p_m_SafePointerList;
        *v13 = v12;
        v16 = (__int64 *)&v16;
        p_m_SafePointerList = &v16;
      }
      v18 = 0i64;
      v14 = v16;
      v15 = p_m_SafePointerList;
      v16[1] = (__int64)p_m_SafePointerList;
      *v15 = v14;
      v16 = (__int64 *)&v16;
      p_m_SafePointerList = &v16;
    }
  }
}fePointerList;
      *v15 = v14;
      v16 = (__int64 *

// File Line: 76
// RVA: 0x342510
void __fastcall UFG::PedKnowledgeLOSSystem::AsyncRaycastCallback(
        UFG::RayCastData *raycastData,
        UFG::SimComponent *pSimComponent,
        void *pCallbackUserData)
{
  char *v5; // rsi
  UFG::SimObjectGame *v6; // rcx
  bool hit; // al
  bool v8; // bl
  hkpRigidBody *mHavokRigidBody; // rax
  unsigned __int64 m_userData; // rax
  __int64 v11; // rax
  UFG::VehicleOccupantComponent *v12; // rdi
  __int16 m_Flags; // dx
  UFG::CharacterOccupantComponent *m_pComponent; // rax
  char *v15; // rcx
  unsigned __int64 mSimTimeMSec; // rdx
  char v17; // al

  if ( pSimComponent )
  {
    v5 = (char *)UFG::PedKnowledgeLOSSystem::ms_pInstance + 64 * (unsigned __int64)(unsigned int)pCallbackUserData;
    if ( *((_QWORD *)v5 + 4) )
    {
      v6 = (UFG::SimObjectGame *)*((_QWORD *)v5 + 7);
      if ( v6 )
      {
        hit = raycastData->hit;
        v8 = !hit;
        if ( hit )
        {
          mHavokRigidBody = raycastData->mHavokRigidBody;
          if ( mHavokRigidBody )
          {
            m_userData = mHavokRigidBody->m_userData;
            if ( m_userData )
            {
              v11 = *(_QWORD *)(m_userData + 24);
              v12 = v11 ? *(UFG::VehicleOccupantComponent **)(v11 + 40) : 0i64;
              v8 = v12 == (UFG::VehicleOccupantComponent *)v6;
              if ( v12 != (UFG::VehicleOccupantComponent *)v6 )
              {
                m_Flags = v6->m_Flags;
                if ( (m_Flags & 0x4000) != 0 )
                {
                  m_pComponent = (UFG::CharacterOccupantComponent *)v6->m_Components.p[44].m_pComponent;
                }
                else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
                {
                  m_pComponent = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                      v6,
                                                                      UFG::CharacterOccupantComponent::_TypeUID);
                }
                else
                {
                  m_pComponent = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                                      v6,
                                                                      UFG::CharacterOccupantComponent::_TypeUID);
                }
                if ( m_pComponent )
                  v8 = UFG::CharacterOccupantComponent::GetCurrentVehicle(m_pComponent) == v12;
              }
            }
          }
        }
        v15 = (char *)pSimComponent[21].m_BoundComponentHandles.mNode.mPrev + 56 * *((unsigned int *)v5 + 16);
        v15[48] &= ~1u;
        v15[48] |= v8;
        mSimTimeMSec = UFG::Metrics::msInstance.mSimTimeMSec;
        v17 = v15[48];
        *((_QWORD *)v15 + 4) = UFG::Metrics::msInstance.mSimTimeMSec;
        if ( v8 )
        {
          *((_QWORD *)v15 + 3) = mSimTimeMSec;
          v15[48] = v17 | 2;
        }
      }
    }
  }
}

// File Line: 116
// RVA: 0x383010
void __fastcall UFG::PedKnowledgeLOSSystem::ResetFrame(UFG::PedKnowledgeLOSSystem *this)
{
  this->m_aLOSData.size = 0;
  this->m_fLowestPriority = -3.4028235e38;
  this->m_iLowestPriorityIndex = -1;
}

// File Line: 123
// RVA: 0x340F80
void __fastcall UFG::PedKnowledgeLOSSystem::AddTest(
        UFG::PedKnowledgeLOSSystem *this,
        UFG::SimObject *pInitiator,
        UFG::SimObject *pTarget,
        unsigned int uIndex,
        float fPriority)
{
  unsigned int size; // ecx
  UFG::PedKnowledgeLOSData *p; // r8
  UFG::PedKnowledgeLOSData *v10; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *p_pInitiatorSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *p_pTargetSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v18; // rax
  unsigned int v19; // edx
  unsigned int v20; // eax
  float v21; // xmm0_4
  UFG::PedKnowledgeLOSData *v22; // rcx
  float v23; // xmm1_4

  if ( fPriority > this->m_fLowestPriority )
  {
    size = this->m_aLOSData.size;
    p = this->m_aLOSData.p;
    if ( size >= this->m_uMaxLOSTestsPerFrame )
    {
      v10 = &p[(unsigned __int64)(unsigned int)this->m_iLowestPriorityIndex];
    }
    else
    {
      v10 = &p[(unsigned __int64)size];
      this->m_aLOSData.size = size + 1;
    }
    p_pInitiatorSimObject = &v10->pInitiatorSimObject;
    v10->fPriority = fPriority;
    if ( v10->pInitiatorSimObject.m_pPointer )
    {
      mPrev = p_pInitiatorSimObject->mPrev;
      mNext = v10->pInitiatorSimObject.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_pInitiatorSimObject->mPrev = p_pInitiatorSimObject;
      v10->pInitiatorSimObject.mNext = &v10->pInitiatorSimObject;
    }
    v10->pInitiatorSimObject.m_pPointer = pInitiator;
    if ( pInitiator )
    {
      v14 = pInitiator->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
      v14->mNext = p_pInitiatorSimObject;
      p_pInitiatorSimObject->mPrev = v14;
      v10->pInitiatorSimObject.mNext = &pInitiator->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
      pInitiator->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_pInitiatorSimObject;
    }
    p_pTargetSimObject = &v10->pTargetSimObject;
    if ( v10->pTargetSimObject.m_pPointer )
    {
      v16 = p_pTargetSimObject->mPrev;
      v17 = v10->pTargetSimObject.mNext;
      v16->mNext = v17;
      v17->mPrev = v16;
      p_pTargetSimObject->mPrev = p_pTargetSimObject;
      v10->pTargetSimObject.mNext = &v10->pTargetSimObject;
    }
    v10->pTargetSimObject.m_pPointer = pTarget;
    if ( pTarget )
    {
      v18 = pTarget->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
      v18->mNext = p_pTargetSimObject;
      p_pTargetSimObject->mPrev = v18;
      v10->pTargetSimObject.mNext = &pTarget->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
      pTarget->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_pTargetSimObject;
    }
    v10->uIndex = uIndex;
    v19 = this->m_aLOSData.size;
    if ( this->m_aLOSData.size == this->m_uMaxLOSTestsPerFrame )
    {
      v20 = 0;
      this->m_fLowestPriority = 3.4028235e38;
      if ( v19 )
      {
        v21 = FLOAT_3_4028235e38;
        v22 = this->m_aLOSData.p;
        do
        {
          v23 = v22->fPriority;
          if ( v22->fPriority < v21 )
          {
            v21 = v22->fPriority;
            this->m_iLowestPriorityIndex = v20;
            this->m_fLowestPriority = v23;
          }
          ++v20;
          ++v22;
        }
        while ( v20 < v19 );
      }
    }
  }
}

