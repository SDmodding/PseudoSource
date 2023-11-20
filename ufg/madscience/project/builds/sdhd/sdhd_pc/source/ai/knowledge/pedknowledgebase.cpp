// File Line: 23
// RVA: 0x14AD380
__int64 dynamic_initializer_for__UFG::PedKnowledgeBase::ms_defaultKnowledgeRecord__()
{
  UFG::PedKnowledgeBase::ms_defaultKnowledgeRecord.pSimObject.m_pPointer = 0i64;
  UFG::PedKnowledgeBase::ms_defaultKnowledgeRecord.m_uLastTimeSeen = 0i64;
  UFG::PedKnowledgeBase::ms_defaultKnowledgeRecord.m_uLastLOSTest = 0i64;
  UFG::PedKnowledgeBase::ms_defaultKnowledgeRecord.m_uLastPathTest = 0i64;
  *((_BYTE *)&UFG::PedKnowledgeBase::ms_defaultKnowledgeRecord + 48) = *((_BYTE *)&UFG::PedKnowledgeBase::ms_defaultKnowledgeRecord
                                                                       + 48) & 0xFC | 4;
  return atexit(dynamic_atexit_destructor_for__UFG::PedKnowledgeBase::ms_defaultKnowledgeRecord__);
}

// File Line: 89
// RVA: 0x391870
void __fastcall UFG::PedKnowledgeBase::Update(UFG::PedKnowledgeBase *this, float fDeltaTime)
{
  UFG::PedKnowledgeBase *v2; // rsi
  UFG::SimObjectCVBase *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::ActiveAIEntityComponent *v5; // rax
  UFG::SimComponent *v6; // rbx
  unsigned int v7; // er14
  UFG::qVector3 *v8; // r15
  unsigned int v9; // ebx
  __int64 v10; // rdi
  UFG::PedKnowledgeRecord *v11; // rbp
  float fPriority; // xmm0_4

  v2 = this;
  if ( this->m_bEnabled )
  {
    v3 = (UFG::SimObjectCVBase *)this->m_pParentSimObject.m_pPointer;
    if ( v3 )
    {
      v4 = v3->m_Flags;
      if ( (v4 >> 14) & 1 )
      {
        v5 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
      }
      else if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
          v5 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v3->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        else
          v5 = (UFG::ActiveAIEntityComponent *)((v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   (UFG::SimObjectGame *)&v3->vfptr,
                                                                   UFG::ActiveAIEntityComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::ActiveAIEntityComponent::_TypeUID));
      }
      else
      {
        v5 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
      }
      if ( v5 )
      {
        v6 = v5->m_pTransformNodeComponent.m_pSimComponent;
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v5->m_pTransformNodeComponent.m_pSimComponent);
        v7 = v2->m_aHostilePedRecords.size;
        v8 = (UFG::qVector3 *)&v6[2].m_BoundComponentHandles;
        v9 = 0;
        if ( v7 )
        {
          v10 = 0i64;
          do
          {
            v11 = &v2->m_aHostilePedRecords.p[v10];
            if ( v11->pSimObject.m_pPointer )
            {
              fPriority = UFG::PedKnowledgeBase::GetLineOfSightPriority(v2, v8, &v2->m_aHostilePedRecords.p[v10]);
              UFG::PedKnowledgeLOSSystem::AddTest(
                UFG::PedKnowledgeLOSSystem::ms_pInstance,
                v2->m_pParentSimObject.m_pPointer,
                v11->pSimObject.m_pPointer,
                v9,
                fPriority);
            }
            ++v9;
            ++v10;
          }
          while ( v9 < v7 );
        }
      }
    }
  }
}

// File Line: 117
// RVA: 0x340B90
void __fastcall UFG::PedKnowledgeBase::AddRecordForHostile(UFG::PedKnowledgeBase *this, UFG::SimObject *pNewHostile)
{
  __int64 v2; // rbp
  UFG::qArray<UFG::PedKnowledgeRecord,15> *v3; // rbx
  UFG::SimObject *v4; // rdi
  unsigned int v5; // esi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax

  v2 = this->m_aHostilePedRecords.size;
  v3 = &this->m_aHostilePedRecords;
  v4 = pNewHostile;
  v5 = v2 + 1;
  if ( (unsigned int)(v2 + 1) > this->m_aHostilePedRecords.capacity )
    UFG::qArray<UFG::PedKnowledgeRecord,15>::Reallocate(
      &this->m_aHostilePedRecords,
      15 * (v5 / 0xF + (v5 != 15 * (v5 / 0xF))),
      "qArray.Add");
  v3->size = v5;
  v6 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->p[v2].pSimObject.mPrev;
  if ( v6[1].mPrev )
  {
    v7 = v6->mPrev;
    v8 = v6->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v6->mPrev = v6;
    v6->mNext = v6;
  }
  v6[1].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)v4;
  if ( v4 )
  {
    v9 = v4->m_SafePointerList.mNode.mPrev;
    v9->mNext = v6;
    v6->mPrev = v9;
    v6->mNext = &v4->m_SafePointerList.mNode;
    v4->m_SafePointerList.mNode.mPrev = v6;
  }
}

// File Line: 123
// RVA: 0x380350
void __fastcall UFG::PedKnowledgeBase::RefreshHostileList(UFG::PedKnowledgeBase *this, float fDeltaTime)
{
  UFG::PedKnowledgeBase *v2; // rdi
  UFG::SimObjectCVBase *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::ActiveAIEntityComponent *v5; // rax
  UFG::ActiveAIEntityComponent *v6; // r13
  UFG::NearbyCharacterManager *v7; // r8
  __int64 **v8; // rbx
  __int64 **v9; // rax
  __int64 **v10; // r12
  _QWORD *v11; // rdx
  __int64 *v12; // rcx
  __int64 *v13; // rax
  UFG::NearbyCharacterManager *v14; // rcx
  __int64 *v15; // rdx
  __int64 **v16; // rax
  __int64 v17; // r14
  signed __int64 i; // rbx
  __int64 v19; // rsi
  UFG::AttackRightsComponent *v20; // r15
  unsigned int v21; // ebx
  __int64 *v22; // rsi
  UFG::SimObject *v23; // rdx
  unsigned int v24; // ecx
  UFG::SimObject **v25; // rax
  __int64 v26; // r9
  signed __int64 v27; // r11
  UFG::PedKnowledgeRecord *v28; // rcx
  signed __int64 v29; // r8
  signed __int64 v30; // rdx
  __int64 v31; // r10
  __int64 v32; // rcx
  _QWORD *v33; // rax
  __int64 v34; // rax
  char v35; // cl
  unsigned int v36; // eax
  __int64 j; // rax
  _QWORD *v38; // rdx
  __int64 v39; // rcx
  _QWORD *v40; // rax
  __int64 *v41; // rcx
  __int64 **v42; // rax
  __int64 v43; // [rsp+0h] [rbp-D8h]
  __int64 v44; // [rsp+10h] [rbp-C8h]
  __int64 *v45; // [rsp+20h] [rbp-B8h]
  __int64 **v46; // [rsp+28h] [rbp-B0h]
  __int64 v47; // [rsp+30h] [rbp-A8h]
  char dest[24]; // [rsp+40h] [rbp-98h]
  __int64 v49[69]; // [rsp+58h] [rbp-80h]

  v47 = -2i64;
  v2 = this;
  if ( this->m_bEnabled )
  {
    v3 = (UFG::SimObjectCVBase *)this->m_pParentSimObject.m_pPointer;
    if ( v3 )
    {
      v4 = v3->m_Flags;
      if ( (v4 >> 14) & 1 )
      {
        v5 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
      }
      else if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
          v5 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v3->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        else
          v5 = (UFG::ActiveAIEntityComponent *)((v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   (UFG::SimObjectGame *)&v3->vfptr,
                                                                   UFG::ActiveAIEntityComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::ActiveAIEntityComponent::_TypeUID));
      }
      else
      {
        v5 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v3);
      }
      v6 = v5;
      if ( v5 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v5->m_pTransformNodeComponent.m_pSimComponent);
        v45 = (__int64 *)&v45;
        v46 = &v45;
        v7 = UFG::NearbyCharacterManager::s_pInstance;
        v8 = &v45;
        v9 = (__int64 **)&v44;
        v10 = (__int64 **)(&v43 + 2);
        if ( &v44 != (__int64 *)v10 )
        {
          do
          {
            v11 = v9 + 2;
            v12 = v9[2];
            v13 = v9[3];
            v12[1] = (__int64)v13;
            *v13 = (__int64)v12;
            *v11 = v11;
            v11[1] = v11;
            v8 = v46;
            v9 = v46 - 2;
          }
          while ( v46 - 2 != v10 );
        }
        v14 = (UFG::NearbyCharacterManager *)v7->m_Characters[0].mNode.mNext;
        if ( v14 != v7 )
        {
          v15 = v45;
          do
          {
            v16 = (__int64 **)&v14->m_Characters[1];
            v15[1] = (__int64)&v14->m_Characters[1];
            *v16 = v15;
            v16[1] = (__int64 *)&v45;
            v15 = (__int64 *)&v14->m_Characters[1];
            v45 = (__int64 *)&v14->m_Characters[1];
            v14 = (UFG::NearbyCharacterManager *)v14->m_Characters[0].mNode.mNext;
          }
          while ( v14 != v7 );
          v8 = v46;
        }
        v17 = 0i64;
        for ( i = (signed __int64)(v8 - 2); (__int64 **)i != v10; i = *(_QWORD *)(i + 24) - 16i64 )
        {
          v19 = *(_QWORD *)(i + 48);
          if ( v19 )
          {
            v20 = *(UFG::AttackRightsComponent **)(v19 + 328);
            if ( UFG::ActiveAIEntityComponent::IsEnemyOfMine(v6, *(UFG::AttackRightsComponent **)(v19 + 328))
              && v20
              && UFG::ActiveAIEntityComponent::CanBeEngagedShared(v6, v20) )
            {
              v49[v17] = *(_QWORD *)(v19 + 40);
              v17 = (unsigned int)(v17 + 1);
            }
          }
        }
        UFG::qMemSet(dest, 0, 0x40u);
        v21 = v2->m_aHostilePedRecords.size;
        if ( (_DWORD)v17 )
        {
          v22 = v49;
          do
          {
            v23 = (UFG::SimObject *)*v22;
            v24 = 0;
            if ( v21 )
            {
              v25 = &v2->m_aHostilePedRecords.p->pSimObject.m_pPointer;
              while ( v23 != *v25 )
              {
                ++v24;
                v25 += 7;
                if ( v24 >= v21 )
                  goto LABEL_34;
              }
              dest[v24] = 1;
            }
            else
            {
LABEL_34:
              UFG::PedKnowledgeBase::AddRecordForHostile(v2, v23);
            }
            ++v22;
            --v17;
          }
          while ( v17 );
        }
        v26 = (signed int)(v21 - 1);
        if ( (signed int)(v21 - 1) >= 0 )
        {
          v27 = (signed int)(v21 - 1);
          do
          {
            if ( !dest[v26] )
            {
              v28 = v2->m_aHostilePedRecords.p;
              v29 = (signed __int64)&v28[v2->m_aHostilePedRecords.size - 1];
              v30 = (signed __int64)&v28[v27];
              v31 = *(_QWORD *)(v29 + 16);
              if ( v28[v27].pSimObject.m_pPointer )
              {
                v32 = *(_QWORD *)v30;
                v33 = *(_QWORD **)(v30 + 8);
                *(_QWORD *)(v32 + 8) = v33;
                *v33 = v32;
                *(_QWORD *)v30 = v30;
                *(_QWORD *)(v30 + 8) = v30;
              }
              *(_QWORD *)(v30 + 16) = v31;
              if ( v31 )
              {
                v34 = *(_QWORD *)(v31 + 8);
                *(_QWORD *)(v34 + 8) = v30;
                *(_QWORD *)v30 = v34;
                *(_QWORD *)(v30 + 8) = v31 + 8;
                *(_QWORD *)(v31 + 8) = v30;
              }
              *(_QWORD *)(v30 + 24) = *(_QWORD *)(v29 + 24);
              *(_QWORD *)(v30 + 32) = *(_QWORD *)(v29 + 32);
              *(_QWORD *)(v30 + 40) = *(_QWORD *)(v29 + 40);
              *(_BYTE *)(v30 + 48) ^= (*(_BYTE *)(v29 + 48) ^ *(_BYTE *)(v30 + 48)) & 1;
              v35 = *(_BYTE *)(v30 + 48) ^ (*(_BYTE *)(v29 + 48) ^ *(_BYTE *)(v30 + 48)) & 2;
              *(_BYTE *)(v30 + 48) = v35;
              *(_BYTE *)(v30 + 48) = v35 ^ (*(_BYTE *)(v29 + 48) ^ v35) & 4;
              v36 = v2->m_aHostilePedRecords.size;
              if ( v36 > 1 )
                v2->m_aHostilePedRecords.size = v36 - 1;
              else
                v2->m_aHostilePedRecords.size = 0;
            }
            --v27;
            --v26;
          }
          while ( v26 >= 0 );
        }
        for ( j = (__int64)(v46 - 2); v46 - 2 != v10; j = (__int64)(v46 - 2) )
        {
          v38 = (_QWORD *)(j + 16);
          v39 = *(_QWORD *)(j + 16);
          v40 = *(_QWORD **)(j + 24);
          *(_QWORD *)(v39 + 8) = v40;
          *v40 = v39;
          *v38 = v38;
          v38[1] = v38;
        }
        v41 = v45;
        v42 = v46;
        v45[1] = (__int64)v46;
        *v42 = v41;
      }
    }
  }
}

// File Line: 204
// RVA: 0x379160
void __fastcall UFG::PedKnowledgeBase::OnAttach(UFG::PedKnowledgeBase *this, UFG::SimObject *pParentSimObj)
{
  UFG::PedKnowledgeBase *v2; // rdi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::PedKnowledgeRecord *v6; // rcx
  char *v7; // rbx
  UFG::PedKnowledgeBase *v8; // [rsp+20h] [rbp-18h]
  void (__fastcall *v9)(UFG::PedKnowledgeBase *, float); // [rsp+28h] [rbp-10h]

  v2 = this;
  if ( this->m_pParentSimObject.m_pPointer )
  {
    v3 = this->m_pParentSimObject.mPrev;
    v4 = this->m_pParentSimObject.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    this->m_pParentSimObject.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->m_pParentSimObject.mPrev;
    this->m_pParentSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->m_pParentSimObject.mPrev;
  }
  this->m_pParentSimObject.m_pPointer = pParentSimObj;
  if ( pParentSimObj )
  {
    v5 = pParentSimObj->m_SafePointerList.mNode.mPrev;
    v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->m_pParentSimObject.mPrev;
    this->m_pParentSimObject.mPrev = v5;
    this->m_pParentSimObject.mNext = &pParentSimObj->m_SafePointerList.mNode;
    pParentSimObj->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->m_pParentSimObject.mPrev;
  }
  v9 = UFG::PedKnowledgeBase::RefreshHostileList;
  v8 = this;
  UFG::TicketBoothManager::Register(
    UFG::TicketBoothManager::mpSingleton,
    TICKETBOOTH_KNOWLEDGEBASE_REFRESHHOSTILES,
    &this->m_ticketRefreshHostiles,
    (fastdelegate::FastDelegate1<float,void> *)&v8);
  v8 = v2;
  v9 = UFG::PedKnowledgeBase::Update;
  UFG::TicketBoothManager::Register(
    UFG::TicketBoothManager::mpSingleton,
    TICKETBOOTH_KNOWLEDGEBASE_UPDATE,
    &v2->m_ticketUpdate,
    (fastdelegate::FastDelegate1<float,void> *)&v8);
  v2->m_bEnabled = 1;
  v6 = v2->m_aHostilePedRecords.p;
  if ( v6 )
  {
    v7 = (char *)&v6[-1] + 48;
    `eh vector destructor iterator'(
      v6,
      0x38ui64,
      *((_DWORD *)&v6[-1] + 12),
      (void (__fastcall *)(void *))UFG::InterestPointUseDetails::~InterestPointUseDetails);
    operator delete[](v7);
  }
  v2->m_aHostilePedRecords.p = 0i64;
  *(_QWORD *)&v2->m_aHostilePedRecords.size = 0i64;
  UFG::PedKnowledgeBase::RefreshHostileList(v2, 0.0);
}

// File Line: 214
// RVA: 0x37B000
void __fastcall UFG::PedKnowledgeBase::OnDetach(UFG::PedKnowledgeBase *this)
{
  UFG::PedKnowledgeBase *v1; // rdi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // rax
  UFG::PedKnowledgeRecord *v4; // rcx
  char *v5; // rbx

  v1 = this;
  if ( this->m_pParentSimObject.m_pPointer )
  {
    v2 = this->m_pParentSimObject.mPrev;
    v3 = this->m_pParentSimObject.mNext;
    v2->mNext = v3;
    v3->mPrev = v2;
    this->m_pParentSimObject.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->m_pParentSimObject.mPrev;
    this->m_pParentSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->m_pParentSimObject.mPrev;
  }
  this->m_pParentSimObject.m_pPointer = 0i64;
  UFG::TicketBoothManager::Unregister(
    UFG::TicketBoothManager::mpSingleton,
    TICKETBOOTH_KNOWLEDGEBASE_REFRESHHOSTILES,
    &this->m_ticketRefreshHostiles);
  UFG::TicketBoothManager::Unregister(
    UFG::TicketBoothManager::mpSingleton,
    TICKETBOOTH_KNOWLEDGEBASE_UPDATE,
    &v1->m_ticketUpdate);
  v4 = v1->m_aHostilePedRecords.p;
  if ( v4 )
  {
    v5 = (char *)&v4[-1] + 48;
    `eh vector destructor iterator'(
      v4,
      0x38ui64,
      *((_DWORD *)&v4[-1] + 12),
      (void (__fastcall *)(void *))UFG::InterestPointUseDetails::~InterestPointUseDetails);
    operator delete[](v5);
  }
  v1->m_aHostilePedRecords.p = 0i64;
  *(_QWORD *)&v1->m_aHostilePedRecords.size = 0i64;
}

// File Line: 225
// RVA: 0x360AD0
float __fastcall UFG::PedKnowledgeBase::GetLineOfSightPriority(UFG::PedKnowledgeBase *this, UFG::qVector3 *vMyPos, UFG::PedKnowledgeRecord *pedKnowledgeRecord)
{
  UFG::TransformNodeComponent *v3; // rbx
  UFG::PedKnowledgeRecord *v4; // rdi
  UFG::qVector3 *v5; // rsi
  __m128 v6; // xmm2
  float v7; // xmm3_4
  float v8; // xmm1_4
  float v9; // xmm0_4

  v3 = (UFG::TransformNodeComponent *)pedKnowledgeRecord->pSimObject.m_pPointer;
  v4 = pedKnowledgeRecord;
  v5 = vMyPos;
  if ( v3 )
    v3 = (UFG::TransformNodeComponent *)v3->mChildren.mNode.mNext;
  UFG::TransformNodeComponent::UpdateWorldTransform(v3);
  v6 = (__m128)LODWORD(v5->y);
  v7 = FLOAT_0_0099999998;
  v6.m128_f32[0] = (float)((float)((float)(v6.m128_f32[0] - v3->mWorldTransform.v3.y)
                                 * (float)(v6.m128_f32[0] - v3->mWorldTransform.v3.y))
                         + (float)((float)(v5->x - v3->mWorldTransform.v3.x) * (float)(v5->x - v3->mWorldTransform.v3.x)))
                 + (float)((float)(v5->z - v3->mWorldTransform.v3.z) * (float)(v5->z - v3->mWorldTransform.v3.z));
  LODWORD(v8) = (unsigned __int128)_mm_sqrt_ps(v6);
  if ( v8 >= 0.0099999998 )
    v7 = v8;
  v9 = (float)(LODWORD(UFG::Metrics::msInstance.mSimTimeMSec) - LODWORD(v4->m_uLastLOSTest));
  if ( (signed __int64)(UFG::Metrics::msInstance.mSimTimeMSec - v4->m_uLastLOSTest) < 0 )
    v9 = v9 + 1.8446744e19;
  return (float)((float)(v9 * 0.001) * UFG::PedKnowledgeBase::ms_fTimePriority)
       + (float)((float)(1.0 / v7) * UFG::PedKnowledgeBase::ms_fDistancePriority);
}

