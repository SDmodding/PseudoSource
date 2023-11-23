// File Line: 80
// RVA: 0x3FDDB0
void __fastcall UFG::WorldEffectsManager::UIElement::UIElement(UFG::WorldEffectsManager::UIElement *this)
{
  this->mHealthFXOverride.m_pPointer = 0i64;
  this->mFightClassFXOverride.m_pPointer = 0i64;
  this->mComponent.mPrev = &this->mComponent;
  this->mComponent.mNext = &this->mComponent;
  this->mComponent.m_pPointer = 0i64;
  this->mTransformNode = 0i64;
  UFG::WorldEffectsManager::UIElement::Reset(this);
}

// File Line: 85
// RVA: 0x4010F0
void __fastcall UFG::WorldEffectsManager::UIElement::Reset(UFG::WorldEffectsManager::UIElement *this)
{
  Render::FXOverride *m_pPointer; // rax
  Render::FXOverride *v3; // rdi
  Render::FXOverride *v4; // rax
  Render::FXOverride *v5; // rdi
  float z; // xmm2_4
  float x; // xmm0_4
  UFG::qSafePointer<UFG::SimComponent,UFG::CharacterEffectsComponent> *p_mComponent; // rbx
  float v9; // xmm2_4
  float v10; // xmm0_4
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax

  this->mIsAlly = 0;
  *(_QWORD *)&this->mHealthUIType = 0i64;
  this->mCurrentHealthUI = HealthUI_1_4;
  m_pPointer = this->mHealthFXOverride.m_pPointer;
  if ( m_pPointer )
  {
    --m_pPointer->mReferenceCount;
    v3 = this->mHealthFXOverride.m_pPointer;
    if ( v3->mReferenceCount <= 0 )
    {
      if ( v3 )
      {
        Render::FXOverride::~FXOverride(this->mHealthFXOverride.m_pPointer);
        operator delete[](v3);
      }
      this->mHealthFXOverride.m_pPointer = 0i64;
    }
    this->mHealthFXOverride.m_pPointer = 0i64;
  }
  this->mHealthUIID = 0;
  v4 = this->mFightClassFXOverride.m_pPointer;
  if ( v4 )
  {
    --v4->mReferenceCount;
    v5 = this->mFightClassFXOverride.m_pPointer;
    if ( v5->mReferenceCount <= 0 )
    {
      if ( v5 )
      {
        Render::FXOverride::~FXOverride(this->mFightClassFXOverride.m_pPointer);
        operator delete[](v5);
      }
      this->mFightClassFXOverride.m_pPointer = 0i64;
    }
    this->mFightClassFXOverride.m_pPointer = 0i64;
  }
  this->mFightClassUIID = 0;
  z = UFG::qVector3::msZero.z;
  x = UFG::qVector3::msZero.x;
  this->mCurrentNormal.y = UFG::qVector3::msZero.y;
  p_mComponent = &this->mComponent;
  *((float *)&p_mComponent[-2].m_pPointer + 1) = x;
  *((float *)&p_mComponent[-1].mPrev + 1) = z;
  v9 = UFG::qVector3::msZero.z;
  v10 = UFG::qVector3::msZero.x;
  HIDWORD(p_mComponent[-1].mNext) = LODWORD(UFG::qVector3::msZero.y);
  *(float *)&p_mComponent[-1].mNext = v10;
  *(float *)&p_mComponent[-1].m_pPointer = v9;
  if ( p_mComponent->m_pPointer )
  {
    mPrev = p_mComponent->mPrev;
    mNext = p_mComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mComponent->mPrev = p_mComponent;
    p_mComponent->mNext = p_mComponent;
  }
  p_mComponent->m_pPointer = 0i64;
}

