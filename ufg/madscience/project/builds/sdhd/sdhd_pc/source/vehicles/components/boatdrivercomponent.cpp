// File Line: 23
// RVA: 0x157B750
__int64 dynamic_initializer_for__UFG::BoatHumanDriverComponent::s_BoatHumanDriverComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::BoatHumanDriverComponent::s_BoatHumanDriverComponentList__);
}

// File Line: 24
// RVA: 0x67B4E0
__int64 __fastcall UFG::qReflectInventory<UFG::Editor::SceneLayerPropertiesWindow>::GetClassSize(
        UFG::qReflectInventory<UFG::Editor::SceneLayerPropertiesWindow> *this)
{
  return 416i64;
}

// File Line: 30
// RVA: 0x666F30
void __fastcall UFG::BoatHumanDriverComponent::BoatHumanDriverComponent(
        UFG::BoatHumanDriverComponent *this,
        unsigned int name_uid)
{
  UFG::qNode<UFG::BoatHumanDriverComponent,UFG::BoatHumanDriverComponent> *mPrev; // rax

  UFG::HumanDriverComponent::HumanDriverComponent(this, name_uid);
  this->UFG::qNode<UFG::BoatHumanDriverComponent,UFG::BoatHumanDriverComponent>::mPrev = &this->UFG::qNode<UFG::BoatHumanDriverComponent,UFG::BoatHumanDriverComponent>;
  this->UFG::qNode<UFG::BoatHumanDriverComponent,UFG::BoatHumanDriverComponent>::mNext = &this->UFG::qNode<UFG::BoatHumanDriverComponent,UFG::BoatHumanDriverComponent>;
  this->UFG::HumanDriverComponent::UFG::VehicleDriverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::BoatHumanDriverComponent::`vftable{for `UFG::SimComponent};
  this->UFG::HumanDriverComponent::UFG::VehicleDriverInterface::UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::BoatHumanDriverComponent::`vftable{for `UFG::UpdateInterface};
  mPrev = UFG::BoatHumanDriverComponent::s_BoatHumanDriverComponentList.mNode.mPrev;
  UFG::BoatHumanDriverComponent::s_BoatHumanDriverComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::BoatHumanDriverComponent,UFG::BoatHumanDriverComponent>;
  this->UFG::qNode<UFG::BoatHumanDriverComponent,UFG::BoatHumanDriverComponent>::mPrev = mPrev;
  this->UFG::qNode<UFG::BoatHumanDriverComponent,UFG::BoatHumanDriverComponent>::mNext = (UFG::qNode<UFG::BoatHumanDriverComponent,UFG::BoatHumanDriverComponent> *)&UFG::BoatHumanDriverComponent::s_BoatHumanDriverComponentList;
  UFG::BoatHumanDriverComponent::s_BoatHumanDriverComponentList.mNode.mPrev = &this->UFG::qNode<UFG::BoatHumanDriverComponent,UFG::BoatHumanDriverComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::BoatHumanDriverComponent::_BoatHumanDriverComponentTypeUID,
    "BoatHumanDriverComponent");
}

// File Line: 38
// RVA: 0x66C170
void __fastcall UFG::BoatHumanDriverComponent::~BoatHumanDriverComponent(UFG::BoatHumanDriverComponent *this)
{
  UFG::qNode<UFG::BoatHumanDriverComponent,UFG::BoatHumanDriverComponent> *v2; // rdx
  UFG::qNode<UFG::BoatHumanDriverComponent,UFG::BoatHumanDriverComponent> *mPrev; // rcx
  UFG::qNode<UFG::BoatHumanDriverComponent,UFG::BoatHumanDriverComponent> *mNext; // rax
  UFG::qNode<UFG::BoatHumanDriverComponent,UFG::BoatHumanDriverComponent> *v5; // rcx
  UFG::qNode<UFG::BoatHumanDriverComponent,UFG::BoatHumanDriverComponent> *v6; // rax

  this->UFG::HumanDriverComponent::UFG::VehicleDriverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::BoatHumanDriverComponent::`vftable{for `UFG::SimComponent};
  this->UFG::HumanDriverComponent::UFG::VehicleDriverInterface::UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::BoatHumanDriverComponent::`vftable{for `UFG::UpdateInterface};
  if ( this == UFG::BoatHumanDriverComponent::s_BoatHumanDriverComponentpCurrentIterator )
    UFG::BoatHumanDriverComponent::s_BoatHumanDriverComponentpCurrentIterator = (UFG::BoatHumanDriverComponent *)&this->UFG::qNode<UFG::BoatHumanDriverComponent,UFG::BoatHumanDriverComponent>::mPrev[-25];
  v2 = &this->UFG::qNode<UFG::BoatHumanDriverComponent,UFG::BoatHumanDriverComponent>;
  mPrev = this->UFG::qNode<UFG::BoatHumanDriverComponent,UFG::BoatHumanDriverComponent>::mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::HumanDriverComponent::~HumanDriverComponent(this);
}

// File Line: 45
// RVA: 0x68F610
void __fastcall UFG::BoatHumanDriverComponent::Update(UFG::BoatHumanDriverComponent *this, float deltaTime)
{
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // r8
  UFG::Controller *v4; // rcx
  int mNext; // eax
  float v6; // xmm1_4
  __int64 mControllerIndex; // r9
  int v8; // ecx
  UFG::InputActionData *v9; // rdx
  UFG::InputActionData *v10; // rax
  UFG::InputActionData *v11; // rax
  UFG::InputActionData *v12; // rax
  UFG::InputActionData *v13; // rax
  UFG::InputActionData *v14; // rax
  UFG::InputActionData *v15; // rax
  UFG::InputActionData *v16; // rax
  float v17; // xmm1_4

  UFG::HumanDriverComponent::Update(this, deltaTime);
  mPrev = this->m_BoundComponentHandles.mNode.UFG::HumanDriverComponent::UFG::VehicleDriverInterface::UFG::SimComponent::mPrev;
  v4 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
  mNext = (int)this->mAudioComponent.mNext;
  v6 = *((float *)&mPrev[43].mPrev + 1) * 3.5999999;
  *(_QWORD *)&this->mBreakOnUpdate = v4;
  if ( mNext == 1 )
  {
LABEL_4:
    LODWORD(mPrev[6].mNext) |= 2u;
    return;
  }
  if ( mNext != 2 )
  {
    if ( (unsigned int)(mNext - 4) > 1 )
      return;
    goto LABEL_4;
  }
  if ( this->mAudioComponent.UFG::HumanDriverComponent::UFG::VehicleDriverInterface::mPrev )
  {
    mControllerIndex = (int)v4->mControllerIndex;
    LODWORD(mPrev[6].mNext) &= ~0x10u;
    v8 = (int)mPrev[6].mNext;
    if ( v6 > 10.0
      && COERCE_FLOAT(LODWORD(mPrev[5].mNext) & _xmm) > 0.89999998
      && (v9 = UFG::ActionDef_HandBrake.mDataPerController[mControllerIndex]) != 0i64
      && v9->mActionTrue )
    {
      LODWORD(mPrev[6].mNext) = v8 | 0x10;
    }
    else if ( COERCE_FLOAT(LODWORD(v6) & _xmm) < 10.0
           && !*(&this->mHangTime.mIsStarted + 1)
           && ((v10 = UFG::ActionDef_Accelerate.mDataPerController[mControllerIndex]) != 0i64 && v10->mActionTrue
            || (v11 = UFG::ActionDef_AccelerateButton.mDataPerController[mControllerIndex]) != 0i64 && v11->mActionTrue)
           && (v12 = UFG::ActionDef_HandBrake.mDataPerController[mControllerIndex]) != 0i64
           && v12->mActionTrue )
    {
      LODWORD(mPrev[6].mPrev) = -1082130432;
      HIDWORD(mPrev[6].mPrev) = -1082130432;
      LODWORD(mPrev[6].mNext) = v8 & 0xFFFFFFDB | 0x20;
    }
    else
    {
      v13 = UFG::ActionDef_HandBrake.mDataPerController[mControllerIndex];
      if ( v13 && v13->mActionTrue
        || ((v14 = UFG::ActionDef_Brake.mDataPerController[mControllerIndex]) != 0i64
         && v14->mActionTrue
         && !BYTE4(this->m_ChaseSpawnTransform->UFG::HumanDriverComponent::UFG::VehicleDriverInterface::m_SafePointerList.mNode.UFG::HumanDriverComponent::UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent>::mNext)
         || (v15 = UFG::ActionDef_BrakeButton.mDataPerController[mControllerIndex]) != 0i64 && v15->mActionTrue)
        && (v16 = UFG::ActionDef_Accelerate.mDataPerController[mControllerIndex]) != 0i64
        && v16->mActionTrue )
      {
        v17 = v6 * 0.1;
        if ( COERCE_FLOAT(LODWORD(v17) & _xmm) > 1.0 )
          v17 = v17 / (float)(COERCE_FLOAT(LODWORD(v17) & _xmm) + 0.00000011920929);
        *(float *)&mPrev[6].mPrev = v17;
        *((float *)&mPrev[6].mPrev + 1) = v17;
        LODWORD(mPrev[6].mNext) = v8 & 0xFFFFFFFE;
      }
    }
  }
}

