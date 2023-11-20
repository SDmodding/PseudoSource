// File Line: 21
// RVA: 0x331440
void __fastcall UFG::PedKnowledgeLOSSystem::PedKnowledgeLOSSystem(UFG::PedKnowledgeLOSSystem *this)
{
  UFG::PedKnowledgeLOSSystem *v1; // rbx

  v1 = this;
  `eh vector constructor iterator'(
    this->m_aLOSData.p,
    0x40ui64,
    200,
    (void (__fastcall *)(void *))UFG::PedKnowledgeLOSData::PedKnowledgeLOSData);
  v1->m_aLOSData.size = 0;
  v1->m_uMaxLOSTestsPerFrame = 10;
}

// File Line: 32
// RVA: 0x33A2D0
void __fastcall UFG::PedKnowledgeLOSSystem::~PedKnowledgeLOSSystem(UFG::PedKnowledgeLOSSystem *this)
{
  this->m_aLOSData.size = 0;
  `eh vector destructor iterator'(
    this->m_aLOSData.p,
    0x40ui64,
    200,
    (void (__fastcall *)(void *))UFG::PedKnowledgeLOSData::~PedKnowledgeLOSData);
}

// File Line: 38
// RVA: 0x3848F0
void __fastcall UFG::PedKnowledgeLOSSystem::SendOffASyncRaycastRequests(UFG::PedKnowledgeLOSSystem *this)
{
  UFG::PedKnowledgeLOSSystem *v1; // rsi
  unsigned int v2; // edi
  unsigned __int64 v3; // rbx
  UFG::SimObject *v4; // rcx
  UFG::SimObjectCVBase *v5; // rcx
  UFG::SimComponent *v6; // rdx
  unsigned __int16 v7; // dx
  UFG::ActiveAIEntityComponent *v8; // rax
  __int64 *v9; // rcx
  __int64 **v10; // rax
  __int64 *v11; // rax
  __int64 *v12; // rcx
  __int64 **v13; // rax
  __int64 *v14; // rcx
  __int64 **v15; // rax
  __int64 *v16; // [rsp+120h] [rbp+20h]
  __int64 **v17; // [rsp+128h] [rbp+28h]
  UFG::SimComponent *v18; // [rsp+130h] [rbp+30h]
  unsigned __int64 v19; // [rsp+138h] [rbp+38h]
  void (__fastcall *v20)(UFG::RayCastData *, UFG::SimComponent *, void *); // [rsp+140h] [rbp+40h]
  UFG::qVector3 v21; // [rsp+150h] [rbp+50h]
  UFG::qVector3 raycastPosition; // [rsp+160h] [rbp+60h]
  __int64 v23; // [rsp+170h] [rbp+70h]

  v23 = -2i64;
  v1 = this;
  v2 = 0;
  if ( this->m_aLOSData.size )
  {
    do
    {
      v3 = (unsigned __int64)v2 << 6;
      v4 = *(UFG::SimObject **)((char *)&v1->m_aLOSData.p[0].pInitiatorSimObject.m_pPointer + v3);
      if ( v4 && *(UFG::SimObject **)((char *)&v1->m_aLOSData.p[0].pTargetSimObject.m_pPointer + v3) )
      {
        UFG::ComputeObjectRaycastPosition(v4, &raycastPosition);
        UFG::ComputeObjectRaycastPosition(
          *(UFG::SimObject **)((char *)&v1->m_aLOSData.p[0].pTargetSimObject.m_pPointer + v3),
          &v21);
        v16 = (__int64 *)&v16;
        v17 = &v16;
        v18 = 0i64;
        v20 = 0i64;
        v19 = v2;
        v5 = *(UFG::SimObjectCVBase **)((char *)&v1->m_aLOSData.p[0].pInitiatorSimObject.m_pPointer + v3);
        if ( v5 )
        {
          v7 = v5->m_Flags;
          if ( (v7 >> 14) & 1 )
          {
            v8 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v5);
          }
          else if ( (v7 & 0x8000u) == 0 )
          {
            if ( (v7 >> 13) & 1 )
            {
              v8 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     (UFG::SimObjectGame *)&v5->vfptr,
                                                     UFG::ActiveAIEntityComponent::_TypeUID);
            }
            else if ( (v7 >> 12) & 1 )
            {
              v8 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     (UFG::SimObjectGame *)&v5->vfptr,
                                                     UFG::ActiveAIEntityComponent::_TypeUID);
            }
            else
            {
              v8 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                     (UFG::SimObject *)&v5->vfptr,
                                                     UFG::ActiveAIEntityComponent::_TypeUID);
            }
          }
          else
          {
            v8 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v5);
          }
          v6 = (UFG::SimComponent *)&v8->vfptr;
        }
        else
        {
          v6 = 0i64;
        }
        if ( v18 )
        {
          v9 = v16;
          v10 = v17;
          v16[1] = (__int64)v17;
          *v10 = v9;
          v16 = (__int64 *)&v16;
          v17 = &v16;
        }
        v18 = v6;
        if ( v6 )
        {
          v11 = (__int64 *)v6->m_SafePointerList.mNode.mPrev;
          v11[1] = (__int64)&v16;
          v16 = v11;
          v17 = (__int64 **)&v6->m_SafePointerList;
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
          (void *)v19);
        if ( v18 )
        {
          v12 = v16;
          v13 = v17;
          v16[1] = (__int64)v17;
          *v13 = v12;
          v16 = (__int64 *)&v16;
          v17 = &v16;
        }
        v18 = 0i64;
        v14 = v16;
        v15 = v17;
        v16[1] = (__int64)v17;
        *v15 = v14;
        v16 = (__int64 *)&v16;
        v17 = &v16;
      }
      ++v2;
    }
    while ( v2 < v1->m_aLOSData.size );
  }
}

// File Line: 76
// RVA: 0x342510
void __fastcall UFG::PedKnowledgeLOSSystem::AsyncRaycastCallback(UFG::RayCastData *raycastData, UFG::SimComponent *pSimComponent, void *pCallbackUserData)
{
  UFG::SimComponent *v3; // rbp
  UFG::RayCastData *v4; // r9
  char *v5; // rsi
  UFG::SimObjectGame *v6; // rcx
  bool v7; // al
  bool v8; // bl
  hkpRigidBody *v9; // rax
  unsigned __int64 v10; // rax
  __int64 v11; // rax
  UFG::VehicleOccupantComponent *v12; // rdi
  unsigned __int16 v13; // dx
  UFG::CharacterOccupantComponent *v14; // rax
  signed __int64 v15; // rcx
  unsigned __int64 v16; // rdx
  char v17; // al

  if ( pSimComponent )
  {
    v3 = pSimComponent;
    v4 = raycastData;
    v5 = (char *)UFG::PedKnowledgeLOSSystem::ms_pInstance + 64 * (unsigned __int64)(unsigned int)pCallbackUserData;
    if ( *((_QWORD *)v5 + 4) )
    {
      v6 = (UFG::SimObjectGame *)*((_QWORD *)v5 + 7);
      if ( v6 )
      {
        v7 = v4->hit;
        v8 = v7 == 0;
        if ( v7 )
        {
          v9 = v4->mHavokRigidBody;
          if ( v9 )
          {
            v10 = v9->m_userData;
            if ( v10 )
            {
              v11 = *(_QWORD *)(v10 + 24);
              v12 = (UFG::VehicleOccupantComponent *)(v11 ? *(_QWORD *)(v11 + 40) : 0i64);
              v8 = v12 == (UFG::VehicleOccupantComponent *)v6;
              if ( v12 != (UFG::VehicleOccupantComponent *)v6 )
              {
                v13 = v6->m_Flags;
                if ( (v13 >> 14) & 1 )
                {
                  v14 = (UFG::CharacterOccupantComponent *)v6->m_Components.p[44].m_pComponent;
                }
                else if ( (v13 & 0x8000u) == 0 )
                {
                  if ( (v13 >> 13) & 1 )
                  {
                    v14 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               v6,
                                                               UFG::CharacterOccupantComponent::_TypeUID);
                  }
                  else if ( (v13 >> 12) & 1 )
                  {
                    v14 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               v6,
                                                               UFG::CharacterOccupantComponent::_TypeUID);
                  }
                  else
                  {
                    v14 = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                               (UFG::SimObject *)&v6->vfptr,
                                                               UFG::CharacterOccupantComponent::_TypeUID);
                  }
                }
                else
                {
                  v14 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             v6,
                                                             UFG::CharacterOccupantComponent::_TypeUID);
                }
                if ( v14 )
                  v8 = UFG::CharacterOccupantComponent::GetCurrentVehicle(v14) == v12;
              }
            }
          }
        }
        v15 = (signed __int64)v3[21].m_BoundComponentHandles.mNode.mPrev + 56 * *((unsigned int *)v5 + 16);
        *(_BYTE *)(v15 + 48) &= 0xFEu;
        *(_BYTE *)(v15 + 48) |= v8;
        v16 = UFG::Metrics::msInstance.mSimTimeMSec;
        v17 = *(_BYTE *)(v15 + 48);
        *(_QWORD *)(v15 + 32) = UFG::Metrics::msInstance.mSimTimeMSec;
        if ( v8 )
        {
          *(_QWORD *)(v15 + 24) = v16;
          *(_BYTE *)(v15 + 48) = v17 | 2;
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
void __fastcall UFG::PedKnowledgeLOSSystem::AddTest(UFG::PedKnowledgeLOSSystem *this, UFG::SimObject *pInitiator, UFG::SimObject *pTarget, unsigned int uIndex, float fPriority)
{
  UFG::SimObject *v5; // rbx
  UFG::SimObject *v6; // r11
  UFG::PedKnowledgeLOSSystem *v7; // r10
  unsigned int v8; // ecx
  signed __int64 v9; // r8
  unsigned __int64 v10; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v18; // rax
  unsigned int v19; // edx
  unsigned int v20; // eax
  float v21; // xmm0_4
  UFG::PedKnowledgeLOSData *v22; // rcx
  float v23; // xmm1_4

  v5 = pTarget;
  v6 = pInitiator;
  v7 = this;
  if ( fPriority > this->m_fLowestPriority )
  {
    v8 = this->m_aLOSData.size;
    v9 = (signed __int64)v7->m_aLOSData.p;
    if ( v8 >= v7->m_uMaxLOSTestsPerFrame )
    {
      v10 = ((unsigned __int64)(unsigned int)v7->m_iLowestPriorityIndex << 6) + v9;
    }
    else
    {
      v10 = ((unsigned __int64)v8 << 6) + v9;
      v7->m_aLOSData.size = v8 + 1;
    }
    v11 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v10 + 8);
    *(float *)v10 = fPriority;
    if ( *(_QWORD *)(v10 + 24) )
    {
      v12 = v11->mPrev;
      v13 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> **)(v10 + 16);
      v12->mNext = v13;
      v13->mPrev = v12;
      v11->mPrev = v11;
      *(_QWORD *)(v10 + 16) = v10 + 8;
    }
    *(_QWORD *)(v10 + 24) = v6;
    if ( v6 )
    {
      v14 = v6->m_SafePointerList.mNode.mPrev;
      v14->mNext = v11;
      v11->mPrev = v14;
      *(_QWORD *)(v10 + 16) = (char *)v6 + 8;
      v6->m_SafePointerList.mNode.mPrev = v11;
    }
    v15 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(v10 + 32);
    if ( *(_QWORD *)(v10 + 48) )
    {
      v16 = v15->mPrev;
      v17 = *(UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> **)(v10 + 40);
      v16->mNext = v17;
      v17->mPrev = v16;
      v15->mPrev = v15;
      *(_QWORD *)(v10 + 40) = v10 + 32;
    }
    *(_QWORD *)(v10 + 48) = v5;
    if ( v5 )
    {
      v18 = v5->m_SafePointerList.mNode.mPrev;
      v18->mNext = v15;
      v15->mPrev = v18;
      *(_QWORD *)(v10 + 40) = (char *)v5 + 8;
      v5->m_SafePointerList.mNode.mPrev = v15;
    }
    *(_DWORD *)(v10 + 56) = uIndex;
    v19 = v7->m_aLOSData.size;
    if ( v7->m_aLOSData.size == v7->m_uMaxLOSTestsPerFrame )
    {
      v20 = 0;
      v7->m_fLowestPriority = 3.4028235e38;
      if ( v19 )
      {
        v21 = FLOAT_3_4028235e38;
        v22 = v7->m_aLOSData.p;
        do
        {
          v23 = v22->fPriority;
          if ( v22->fPriority < v21 )
          {
            v21 = v22->fPriority;
            v7->m_iLowestPriorityIndex = v20;
            v7->m_fLowestPriority = v23;
          }
          ++v20;
          ++v22;
        }
        while ( v20 < v19 );
      }
    }
  }
}

