// File Line: 59
// RVA: 0x1554AC0
__int64 dynamic_initializer_for__UFG::DialogueAnimationComponent::s_DialogueAnimationComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::DialogueAnimationComponent::s_DialogueAnimationComponentList__);
}

// File Line: 60
// RVA: 0x1554850
__int64 dynamic_initializer_for__UFG::DialogueAnimationComponent::_TypeIDesc__()
{
  UFG::ComponentIDDesc *v0; // rax
  __int64 result; // rax

  v0 = UFG::DialogueAnimationComponent::AccessComponentDesc();
  *(_DWORD *)&UFG::DialogueAnimationComponent::_TypeIDesc.mBaseTypeIndex = *(_DWORD *)&v0->mBaseTypeIndex;
  UFG::DialogueAnimationComponent::_TypeIDesc.mChildBitMask = v0->mChildBitMask;
  result = v0->mChildren;
  UFG::DialogueAnimationComponent::_TypeIDesc.mChildren = result;
  return result;
}

// File Line: 81
// RVA: 0x593340
void __fastcall UFG::DialogueAnimationComponent::DialogueAnimationComponent(
        UFG::DialogueAnimationComponent *this,
        UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qNode<UFG::DialogueAnimationComponent,UFG::DialogueAnimationComponent> *mPrev; // rax
  char v4; // cl

  UFG::SimComponent::SimComponent(this, pSceneObj->m_NameUID);
  this->mPrev = &this->UFG::qNode<UFG::DialogueAnimationComponent,UFG::DialogueAnimationComponent>;
  this->mNext = &this->UFG::qNode<UFG::DialogueAnimationComponent,UFG::DialogueAnimationComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::DialogueAnimationComponent::`vftable;
  this->m_currentTime = 0.0;
  *(_WORD *)&this->m_parametricMode = 0;
  *(_QWORD *)&this->m_sampleNameHash = 0i64;
  this->m_animName.mUID = -1;
  this->m_splitBodyBlend.mPrev = &this->m_splitBodyBlend;
  this->m_splitBodyBlend.mNext = &this->m_splitBodyBlend;
  this->m_splitBodyBlend.m_pPointer = 0i64;
  this->m_controller.mPrev = &this->m_controller;
  this->m_controller.mNext = &this->m_controller;
  this->m_controller.m_pPointer = 0i64;
  this->mFacialContext = 0i64;
  *((_BYTE *)this + 168) = *((_BYTE *)this + 168) & 0xF8 | 1;
  this->mActionRequests.mBits[0] = 0i64;
  this->mActionRequests.mBits[1] = 0i64;
  this->mActionRequests.mBits[2] = 0i64;
  this->mActionRequests.mBits[3] = 0i64;
  this->mActionRequests.mBits[4] = 0i64;
  this->mActionRequests.mBits[5] = 0i64;
  this->mActionRequests.mBits[6] = 0i64;
  this->mActionRequests.mBits[7] = 0i64;
  this->mActionRequests.mBits[8] = 0i64;
  mPrev = UFG::DialogueAnimationComponent::s_DialogueAnimationComponentList.mNode.mPrev;
  UFG::DialogueAnimationComponent::s_DialogueAnimationComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::DialogueAnimationComponent,UFG::DialogueAnimationComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::DialogueAnimationComponent,UFG::DialogueAnimationComponent> *)&UFG::DialogueAnimationComponent::s_DialogueAnimationComponentList;
  UFG::DialogueAnimationComponent::s_DialogueAnimationComponentList.mNode.mPrev = &this->UFG::qNode<UFG::DialogueAnimationComponent,UFG::DialogueAnimationComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::DialogueAnimationComponent::_DialogueAnimationComponentTypeUID,
    "DialogueAnimationComponent");
  v4 = UFG::DialogueAnimationComponent::sm_tweakInit;
  if ( !UFG::DialogueAnimationComponent::sm_tweakInit )
    v4 = 1;
  UFG::DialogueAnimationComponent::sm_tweakInit = v4;
}

// File Line: 102
// RVA: 0x5943F0
void __fastcall UFG::DialogueAnimationComponent::~DialogueAnimationComponent(UFG::DialogueAnimationComponent *this)
{
  UFG::qNode<UFG::DialogueAnimationComponent,UFG::DialogueAnimationComponent> *v2; // r9
  UFG::qNode<UFG::DialogueAnimationComponent,UFG::DialogueAnimationComponent> *mPrev; // rcx
  UFG::qNode<UFG::DialogueAnimationComponent,UFG::DialogueAnimationComponent> *mNext; // rax
  UFG::qSafePointer<AnimationNode,AnimationNode> *p_m_controller; // rdx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qSafePointer<PoseNode,PoseNode> *p_m_splitBodyBlend; // rdx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::DialogueAnimationComponent,UFG::DialogueAnimationComponent> *v15; // rcx
  UFG::qNode<UFG::DialogueAnimationComponent,UFG::DialogueAnimationComponent> *v16; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::DialogueAnimationComponent::`vftable;
  if ( this == UFG::DialogueAnimationComponent::s_DialogueAnimationComponentpCurrentIterator )
    UFG::DialogueAnimationComponent::s_DialogueAnimationComponentpCurrentIterator = (UFG::DialogueAnimationComponent *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<UFG::DialogueAnimationComponent,UFG::DialogueAnimationComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  p_m_controller = &this->m_controller;
  if ( this->m_controller.m_pPointer )
  {
    v6 = p_m_controller->mPrev;
    v7 = this->m_controller.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    p_m_controller->mPrev = p_m_controller;
    this->m_controller.mNext = &this->m_controller;
  }
  this->m_controller.m_pPointer = 0i64;
  v8 = p_m_controller->mPrev;
  v9 = this->m_controller.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  p_m_controller->mPrev = p_m_controller;
  this->m_controller.mNext = &this->m_controller;
  p_m_splitBodyBlend = &this->m_splitBodyBlend;
  if ( this->m_splitBodyBlend.m_pPointer )
  {
    v11 = p_m_splitBodyBlend->mPrev;
    v12 = this->m_splitBodyBlend.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    p_m_splitBodyBlend->mPrev = p_m_splitBodyBlend;
    this->m_splitBodyBlend.mNext = &this->m_splitBodyBlend;
  }
  this->m_splitBodyBlend.m_pPointer = 0i64;
  v13 = p_m_splitBodyBlend->mPrev;
  v14 = this->m_splitBodyBlend.mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  p_m_splitBodyBlend->mPrev = p_m_splitBodyBlend;
  this->m_splitBodyBlend.mNext = &this->m_splitBodyBlend;
  v15 = v2->mPrev;
  v16 = v2->mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 110
// RVA: 0x5A87D0
UFG::DialogueAnimationComponent *__fastcall UFG::DialogueAnimationComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *pSceneObj,
        bool required)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v4; // rax
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rdi
  UFG::SimObject *m_pSimObject; // rdx
  unsigned int v8; // ebx
  UFG::SimObjectModifier v10; // [rsp+38h] [rbp-30h] BYREF

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v4 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xF8ui64, "DialogueAnimationComponent", 0i64, 1u);
  if ( v4 )
  {
    UFG::DialogueAnimationComponent::DialogueAnimationComponent((UFG::DialogueAnimationComponent *)v4, pSceneObj);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  m_pSimObject = pSceneObj->m_pSimObject;
  if ( (m_pSimObject->m_Flags & 0x4000) != 0 )
    v8 = 41;
  else
    v8 = -1;
  UFG::SimObjectModifier::SimObjectModifier(&v10, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v10, v6, v8);
  UFG::SimObjectModifier::Close(&v10);
  UFG::SimObjectModifier::~SimObjectModifier(&v10);
  return (UFG::DialogueAnimationComponent *)v6;
}

// File Line: 118
// RVA: 0x5A3990
void __fastcall UFG::DialogueAnimationComponent::OnAttach(
        UFG::DialogueAnimationComponent *this,
        UFG::SimObject *object)
{
  if ( this->m_pSimObject == LocalPlayer )
    *((_BYTE *)this + 168) |= 2u;
  this->mActionRequests.mBits[0] = 0i64;
  this->mActionRequests.mBits[1] = 0i64;
  this->mActionRequests.mBits[2] = 0i64;
  this->mActionRequests.mBits[3] = 0i64;
  this->mActionRequests.mBits[4] = 0i64;
  this->mActionRequests.mBits[5] = 0i64;
  this->mActionRequests.mBits[6] = 0i64;
  this->mActionRequests.mBits[7] = 0i64;
  this->mActionRequests.mBits[8] = 0i64;
}

// File Line: 296
// RVA: 0x5AF130
void __fastcall UFG::DialogueAnimationComponent::Update(UFG::DialogueAnimationComponent *this, float delta_sec)
{
  unsigned int m_sampleNameHash; // edi
  AnimationDataBase *Instance; // rax
  UFG::qBaseTreeRB *v5; // rax
  UFG::qBaseNodeRB *p_mNULL; // rax
  UFG::qBaseNodeRB *v7; // rax
  char v8; // al
  UFG::SimObjectCVBase *m_pSimObject; // rcx
  UFG::AICharacterControllerBaseComponent *v10; // rcx
  __int16 m_Flags; // dx
  UFG::AICharacterControllerBaseComponent *ComponentOfType; // rax
  unsigned int v13; // edx
  bool v14; // zf
  UFG::qWiseSymbol result; // [rsp+48h] [rbp+10h] BYREF

  if ( (*((_BYTE *)this + 168) & 1) != 0 )
  {
    m_sampleNameHash = this->m_sampleNameHash;
    if ( m_sampleNameHash )
    {
      Instance = AnimationDataBase::GetInstance();
      v5 = UFG::qBaseTreeRB::Get(&Instance->mAnimations.mTree, m_sampleNameHash);
      if ( v5 )
      {
        p_mNULL = &v5[-1].mNULL;
        if ( p_mNULL )
        {
          v7 = p_mNULL[3].mChild[0];
          if ( v7 )
          {
            if ( v7[3].mParent )
            {
              this->m_animName.mUID = UFG::qSymbol::qSymbol(&result, this->m_sampleNameHash)->mUID;
              v8 = *((_BYTE *)this + 168) & 0xFE;
              this->m_currentTime = 0.0;
              this->m_lastTime = 0.0;
              this->m_parametricMode = 0;
              this->m_sampleNameHash = 0;
              *((_BYTE *)this + 168) = v8 | 4;
              UFG::DialogueAnimationComponent::PlayFacialAnim(this, APM_NORMAL);
            }
          }
        }
      }
    }
  }
  this->m_currentTime = delta_sec + this->m_currentTime;
  UFG::DialogueAnimationComponent::UpdateAnim(this, delta_sec);
  m_pSimObject = (UFG::SimObjectCVBase *)this->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::AICharacterControllerBaseComponent>(m_pSimObject);
    }
    else
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        v13 = UFG::AICharacterControllerBaseComponent::_TypeUID;
      }
      else
      {
        v14 = (m_Flags & 0x1000) == 0;
        v13 = UFG::AICharacterControllerBaseComponent::_TypeUID;
        if ( v14 )
        {
          ComponentOfType = (UFG::AICharacterControllerBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                         m_pSimObject,
                                                                         UFG::AICharacterControllerBaseComponent::_TypeUID);
          goto LABEL_18;
        }
      }
      ComponentOfType = (UFG::AICharacterControllerBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     m_pSimObject,
                                                                     v13);
    }
LABEL_18:
    v10 = ComponentOfType;
    goto LABEL_19;
  }
  v10 = 0i64;
LABEL_19:
  v10->m_Intention.mActionRequests.mBits[0] |= this->mActionRequests.mBits[0];
  v10->m_Intention.mActionRequests.mBits[1] |= this->mActionRequests.mBits[1];
  v10->m_Intention.mActionRequests.mBits[2] |= this->mActionRequests.mBits[2];
  v10->m_Intention.mActionRequests.mBits[3] |= this->mActionRequests.mBits[3];
  v10->m_Intention.mActionRequests.mBits[4] |= this->mActionRequests.mBits[4];
  v10->m_Intention.mActionRequests.mBits[5] |= this->mActionRequests.mBits[5];
  v10->m_Intention.mActionRequests.mBits[6] |= this->mActionRequests.mBits[6];
  v10->m_Intention.mActionRequests.mBits[7] |= this->mActionRequests.mBits[7];
  v10->m_Intention.mActionRequests.mBits[8] |= this->mActionRequests.mBits[8];
  v10->m_Intention.mSignals = v10->m_Intention.mActionRequests.mBits[0] | v10->m_Intention.mActionRequests.mBits[1] | v10->m_Intention.mActionRequests.mBits[2] | v10->m_Intention.mActionRequests.mBits[3] | v10->m_Intention.mActionRequests.mBits[4] | v10->m_Intention.mActionRequests.mBits[5] | v10->m_Intention.mActionRequests.mBits[6] | v10->m_Intention.mActionRequests.mBits[7] | v10->m_Intention.mActionRequests.mBits[8];
  this->mActionRequests.mBits[0] = 0i64;
  this->mActionRequests.mBits[1] = 0i64;
  this->mActionRequests.mBits[2] = 0i64;
  this->mActionRequests.mBits[3] = 0i64;
  this->mActionRequests.mBits[4] = 0i64;
  this->mActionRequests.mBits[5] = 0i64;
  this->mActionRequests.mBits[6] = 0i64;
  this->mActionRequests.mBits[7] = 0i64;
  this->mActionRequests.mBits[8] = 0i64;
  this->m_lastTime = this->m_currentTime;
}

// File Line: 344
// RVA: 0x5AFEA0
char __fastcall UFG::DialogueAnimationComponent::UpdateAnim(UFG::DialogueAnimationComponent *this, float delta_sec)
{
  AnimationNode *m_pPointer; // rcx
  AnimationNode *v4; // rax
  UFG::ActorAudioComponent *v5; // rbx
  UFG::SimObjectCharacter *m_pSimObject; // rcx
  UFG::ActorAudioComponent *ComponentOfTypeHK; // rax
  __int16 m_Flags; // dx
  UFG::AudioEvent *m_pEvent; // rcx
  AnimationNode *v10; // rax
  char v11; // si
  UFG::SimObjectCharacter *v12; // rcx
  __int16 v13; // dx
  UFG::ActorAudioComponent *ComponentOfType; // rax
  unsigned int v15; // edx
  bool v16; // zf
  float y; // xmm1_4
  float v18; // xmm2_4
  Render::DebugDrawContext *Context; // rbx
  char *v20; // rax
  UFG::qVector3 world_position; // [rsp+30h] [rbp-28h] BYREF
  float result; // [rsp+60h] [rbp+8h] BYREF

  m_pPointer = this->m_controller.m_pPointer;
  if ( m_pPointer )
  {
    AnimationNode::verifyBindAnimation(m_pPointer);
    v4 = this->m_controller.m_pPointer;
    v5 = 0i64;
    if ( !v4 || !v4->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer )
      goto LABEL_24;
    m_pSimObject = (UFG::SimObjectCharacter *)this->m_pSimObject;
    if ( m_pSimObject )
    {
      m_Flags = m_pSimObject->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(m_pSimObject);
      }
      else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      {
        ComponentOfTypeHK = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          m_pSimObject,
                                                          UFG::ActorAudioComponent::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                                          m_pSimObject,
                                                          UFG::ActorAudioComponent::_TypeUID);
      }
    }
    else
    {
      ComponentOfTypeHK = 0i64;
    }
    m_pEvent = ComponentOfTypeHK->m_controller.m_pEvent;
    if ( UFG::DialogueAnimationComponent::sm_correctTimes )
    {
      result = 0.0;
      if ( !m_pEvent || !UFG::AudioEvent::GetElapsedTime(m_pEvent, &result, 1) )
        goto LABEL_22;
      v10 = this->m_controller.m_pPointer;
      result = result * 0.001;
      SkeletalAnimation::GetDuration(v10->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer);
    }
    else
    {
      if ( !m_pEvent || !UFG::AudioEvent::GetElapsedTime(m_pEvent, &result, 1) )
        goto LABEL_22;
      result = result * 0.001;
    }
    ((void (__fastcall *)(AnimationNode *))this->m_controller.m_pPointer->vfptr[3].GetResourcePath)(this->m_controller.m_pPointer);
LABEL_22:
    if ( !((unsigned __int8 (__fastcall *)(AnimationNode *))this->m_controller.m_pPointer->vfptr[1].SetResourceOwner)(this->m_controller.m_pPointer) )
    {
      v11 = 1;
LABEL_25:
      if ( !UFG::DialogueAnimationComponent::sm_debugFace )
        return v11;
      v12 = (UFG::SimObjectCharacter *)this->m_pSimObject;
      if ( !v12 )
      {
LABEL_37:
        y = v5->m_WorldMatrix.v3.y;
        v18 = v5->m_WorldMatrix.v3.z + 1.3;
        world_position.x = v5->m_WorldMatrix.v3.x;
        world_position.y = y;
        world_position.z = v18;
        Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(
                                                Render::DebugDrawManager::mInstance,
                                                3u);
        v20 = UFG::qSymbol::as_cstr_dbg(&this->m_animName);
        Render::DebugDrawContext::DrawText(
          Context,
          &world_position,
          &UFG::qColour::Red,
          "Playing: %2.2f  %s",
          this->m_currentTime,
          v20);
        return v11;
      }
      v13 = v12->m_Flags;
      if ( (v13 & 0x4000) != 0 )
      {
        ComponentOfType = UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(v12);
      }
      else
      {
        if ( v13 < 0 || (v13 & 0x2000) != 0 )
        {
          v15 = UFG::ActorAudioComponent::_TypeUID;
        }
        else
        {
          v16 = (v13 & 0x1000) == 0;
          v15 = UFG::ActorAudioComponent::_TypeUID;
          if ( v16 )
          {
            ComponentOfType = (UFG::ActorAudioComponent *)UFG::SimObject::GetComponentOfType(
                                                            v12,
                                                            UFG::ActorAudioComponent::_TypeUID);
            goto LABEL_36;
          }
        }
        ComponentOfType = (UFG::ActorAudioComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v12, v15);
      }
LABEL_36:
      v5 = ComponentOfType;
      goto LABEL_37;
    }
    this->m_controller.m_pPointer->vfptr[1].GetResourceOwner(this->m_controller.m_pPointer);
LABEL_24:
    v11 = 0;
    goto LABEL_25;
  }
  return 0;
}

// File Line: 415
// RVA: 0x59B650
void __fastcall UFG::DialogueAnimationComponent::EndFacialAnim(UFG::DialogueAnimationComponent *this)
{
  char *v2; // rax
  PoseNode *m_pPointer; // rax

  if ( this->m_controller.m_pPointer )
  {
    if ( this->m_splitBodyBlend.m_pPointer )
    {
      if ( UFG::DialogueAnimationComponent::sm_debugFace )
      {
        v2 = UFG::qSymbol::as_cstr_dbg(&this->m_animName);
        UFG::qPrintf("Fac Anim Trc: Ending : %s\n", v2);
      }
      m_pPointer = this->m_splitBodyBlend.m_pPointer;
      if ( UFG::DialogueAnimationComponent::sm_blendOut == 0.0 )
      {
        HIDWORD(m_pPointer[1].mParent.mOffset) = -1082130432;
        m_pPointer[1].mPriority = 0;
LABEL_9:
        BYTE3(m_pPointer[1].mParent.mOffset) = 0;
        goto LABEL_10;
      }
      if ( UFG::DialogueAnimationComponent::sm_blendOut > 0.0 )
      {
        *((float *)&m_pPointer[1].mParent.mOffset + 1) = -1.0 / UFG::DialogueAnimationComponent::sm_blendOut;
        goto LABEL_9;
      }
    }
LABEL_10:
    this->m_animName = UFG::gNullQSymbolUC;
  }
}

// File Line: 480
// RVA: 0x155D120
__int64 UFG::_dynamic_initializer_for__symFaceInGame__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("FaceInGame", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::symFaceInGame, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symFaceInGame__);
}

// File Line: 483
// RVA: 0x5A5990
void __fastcall UFG::DialogueAnimationComponent::PlayFacialAnim(
        UFG::DialogueAnimationComponent *this,
        AnimationPlayMode mode)
{
  char *v4; // rax
  UFG::SimObjectCVBase *m_pPointer; // rcx
  AnimationNode *v6; // rsi
  UFG::CharacterAnimationComponent *v7; // rax
  __int16 m_Flags; // dx
  Creature *mCreature; // r15
  char *v10; // rax
  PoseNodeParent *v11; // rax
  PoseNodeParent *v12; // rbp
  UFG::qSafePointer<PoseNode,PoseNode> *p_m_splitBodyBlend; // r8
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v16; // rax
  PoseNode *v17; // rbx
  char *v18; // rax
  AnimationNode *v19; // rax
  UFG::qSafePointer<AnimationNode,AnimationNode> *p_m_controller; // rdx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v21; // rcx
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v22; // rax
  UFG::qNode<UFG::qSafePointerBase<AnimationNode>,UFG::qSafePointerNodeList> *v23; // rax
  UFG::SimObjectCharacter *m_pSimObject; // rcx
  __int16 v25; // dx
  unsigned int v26; // edx
  bool v27; // zf
  int returnCode; // [rsp+B0h] [rbp+18h] BYREF
  char *v29; // [rsp+B8h] [rbp+20h]

  if ( UFG::DialogueAnimationComponent::SetFacialActionContext(this)
    && this->m_animName.mUID != UFG::gNullQSymbolUC.mUID )
  {
    if ( UFG::DialogueAnimationComponent::sm_debugFace )
    {
      v4 = UFG::qSymbol::as_cstr_dbg(&this->m_animName);
      UFG::qPrintf("Fac Anim Trc: Playing : %s\n", v4);
    }
    m_pPointer = (UFG::SimObjectCVBase *)this->mFacialContext->mSimObject.m_pPointer;
    v6 = 0i64;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      {
        v7 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(m_pPointer);
      }
      else if ( (m_Flags & 0x2000) != 0 )
      {
        v7 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)m_pPointer);
      }
      else
      {
        v7 = (UFG::CharacterAnimationComponent *)((m_Flags & 0x1000) != 0
                                                ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    m_pPointer,
                                                    UFG::CharacterAnimationComponent::_TypeUID)
                                                : UFG::SimObject::GetComponentOfType(
                                                    m_pPointer,
                                                    UFG::CharacterAnimationComponent::_TypeUID));
      }
    }
    else
    {
      v7 = 0i64;
    }
    mCreature = v7->mCreature;
    if ( mCreature )
    {
      v10 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0xB0ui64, "BlendAddNode", 0i64, 1u);
      v29 = v10;
      if ( v10 )
      {
        BlendAddNode::BlendAddNode((BlendAddNode *)v10, UFG::DialogueAnimationComponent::sm_blendIn);
        v12 = v11;
      }
      else
      {
        v12 = 0i64;
      }
      p_m_splitBodyBlend = &this->m_splitBodyBlend;
      if ( this->m_splitBodyBlend.m_pPointer )
      {
        mPrev = p_m_splitBodyBlend->mPrev;
        mNext = this->m_splitBodyBlend.mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        p_m_splitBodyBlend->mPrev = p_m_splitBodyBlend;
        this->m_splitBodyBlend.mNext = &this->m_splitBodyBlend;
      }
      this->m_splitBodyBlend.m_pPointer = v12;
      if ( v12 )
      {
        v16 = v12->m_SafePointerList.mNode.PoseNode::UFG::qSafePointerNode<PoseNode>::mPrev;
        v16->mNext = p_m_splitBodyBlend;
        p_m_splitBodyBlend->mPrev = v16;
        this->m_splitBodyBlend.mNext = &v12->m_SafePointerList.mNode;
        v12->m_SafePointerList.mNode.PoseNode::UFG::qSafePointerNode<PoseNode>::mPrev = p_m_splitBodyBlend;
      }
      v17 = this->m_splitBodyBlend.m_pPointer;
      v17[1].mPrev = (UFG::qNode<PoseNode,PoseNode> *)Creature::GetWeightSet(mCreature, &UFG::symFaceInGame);
      v18 = UFG::qMemoryPool2::Allocate(
              &gActionTreeMemoryPool,
              0x170ui64,
              "DialogueAnimationComponent.AnimationNode",
              0i64,
              1u);
      v29 = v18;
      if ( v18 )
      {
        AnimationNode::AnimationNode((AnimationNode *)v18, &this->m_animName, mode, 0.0, -1.0);
        v6 = v19;
      }
      p_m_controller = &this->m_controller;
      if ( this->m_controller.m_pPointer )
      {
        v21 = p_m_controller->mPrev;
        v22 = this->m_controller.mNext;
        v21->mNext = v22;
        v22->mPrev = v21;
        p_m_controller->mPrev = p_m_controller;
        this->m_controller.mNext = &this->m_controller;
      }
      this->m_controller.m_pPointer = v6;
      if ( v6 )
      {
        v23 = v6->UFG::qSafePointerNode<AnimationNode>::m_SafePointerList.mNode.UFG::qSafePointerNode<AnimationNode>::mPrev;
        v23->mNext = p_m_controller;
        p_m_controller->mPrev = v23;
        this->m_controller.mNext = &v6->UFG::qSafePointerNode<AnimationNode>::m_SafePointerList.mNode;
        v6->UFG::qSafePointerNode<AnimationNode>::m_SafePointerList.mNode.UFG::qSafePointerNode<AnimationNode>::mPrev = p_m_controller;
      }
      this->m_controller.m_pPointer->vfptr[3].ResolveReferences(this->m_controller.m_pPointer);
      m_pSimObject = (UFG::SimObjectCharacter *)this->m_pSimObject;
      if ( !m_pSimObject )
        goto LABEL_38;
      v25 = m_pSimObject->m_Flags;
      if ( (v25 & 0x4000) != 0 )
      {
        UFG::SimObjectCharacter::GetComponent<UFG::ActorAudioComponent>(m_pSimObject);
      }
      else
      {
        if ( v25 < 0 || (v25 & 0x2000) != 0 )
        {
          v26 = UFG::ActorAudioComponent::_TypeUID;
        }
        else
        {
          v27 = (v25 & 0x1000) == 0;
          v26 = UFG::ActorAudioComponent::_TypeUID;
          if ( v27 )
          {
            UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::ActorAudioComponent::_TypeUID);
            goto LABEL_38;
          }
        }
        UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, v26);
      }
LABEL_38:
      Creature::PlayBlendTree(mCreature, this->m_controller.m_pPointer, v12, 0xAu, 0, 0.0, -1.0, &returnCode);
      ((void (__fastcall *)(AnimationNode *, ActionContext *))this->m_controller.m_pPointer->vfptr[2].GetResourceOwner)(
        this->m_controller.m_pPointer,
        this->mFacialContext);
    }
  }
}

// File Line: 513
// RVA: 0x5AC870
void __fastcall UFG::DialogueAnimationComponent::Stop(UFG::DialogueAnimationComponent *this)
{
  UFG::qSymbolUC *p_m_animName; // rcx
  char *v3; // rax

  if ( UFG::DialogueAnimationComponent::sm_debugFace )
  {
    p_m_animName = &this->m_animName;
    if ( p_m_animName->mUID != -1 )
    {
      v3 = UFG::qSymbol::as_cstr_dbg(p_m_animName);
      UFG::qPrintf("Fac Anim Trc: Stop : %s\n", v3);
    }
  }
  UFG::DialogueAnimationComponent::EndFacialAnim(this);
  *((_BYTE *)this + 168) = *((_BYTE *)this + 168) & 0xFA | 1;
  this->m_currentTime = 0.0;
  this->m_lastTime = 0.0;
  this->m_parametricMode = 0;
  *(_QWORD *)&this->m_sampleNameHash = 0i64;
  this->m_animName = UFG::gNullQSymbolUC;
}

// File Line: 551
// RVA: 0x5AAE60
char __fastcall UFG::DialogueAnimationComponent::SetFacialActionContext(UFG::DialogueAnimationComponent *this)
{
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax

  m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( !m_pSimObject )
    goto LABEL_11;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pSimObject->m_Components.p[31].m_pComponent;
  }
  else
  {
    if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 )
      goto LABEL_11;
    if ( (m_Flags & 0x1000) != 0 )
      m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::FacialActionTreeComponent::_TypeUID);
    else
      m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::FacialActionTreeComponent::_TypeUID);
  }
  if ( m_pComponent )
  {
    this->mFacialContext = (ActionContext *)m_pComponent[3].vfptr;
    return 1;
  }
LABEL_11:
  this->mFacialContext = 0i64;
  return 0;
}

