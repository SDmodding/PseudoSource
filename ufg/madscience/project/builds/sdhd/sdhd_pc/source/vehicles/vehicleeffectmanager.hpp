// File Line: 100
// RVA: 0x66AE60
void __fastcall UFG::VehicleEffect::VehicleEffect(UFG::VehicleEffect *this, const char *name)
{
  const char *v2; // rbx
  UFG::VehicleEffect *v3; // rdi
  unsigned int v4; // eax
  Render::FXOverride *v5; // rax
  Render::FXOverride *v6; // rbx

  v2 = name;
  v3 = this;
  v4 = UFG::qStringHashUpper32(name, 0xFFFFFFFF);
  v3->mNode.mParent = 0i64;
  v3->mNode.mChild[0] = 0i64;
  v3->mNode.mChild[1] = 0i64;
  v3->mNode.mUID = v4;
  UFG::qSymbol::create_from_string(&v3->mName, v2);
  v3->mTransform.mUID = -1;
  v3->mMarkerHash.mUID = -1;
  v3->mDamageAffectorHash.mUID = -1;
  v3->mDamageBoneHash.mUID = -1;
  v3->mEffectOverride.m_pPointer = 0i64;
  UFG::qSymbol::set_null(&v3->mTransform);
  v3->mMarker = -1;
  v3->mMarkerHash = UFG::gNullQSymbolUC;
  v3->mDamageBone = -1;
  v3->mDamageBoneHash = UFG::gNullQSymbolUC;
  v3->mDamageAffectorBone = -1;
  v3->mDamageAffectorHash = UFG::gNullQSymbolUC;
  *(_QWORD *)&v3->mForwardBone = -1i64;
  v3->mEffectRef = -1;
  v5 = v3->mEffectOverride.m_pPointer;
  if ( v5 )
  {
    --v5->mReferenceCount;
    v6 = v3->mEffectOverride.m_pPointer;
    if ( v6->mReferenceCount <= 0 )
    {
      if ( v6 )
      {
        Render::FXOverride::~FXOverride(v3->mEffectOverride.m_pPointer);
        operator delete[](v6);
      }
      v3->mEffectOverride.m_pPointer = 0i64;
    }
    v3->mEffectOverride.m_pPointer = 0i64;
  }
  v3->mDamageMarkerIndex = -1;
  *(_QWORD *)&v3->mRequestedSpeed = 0i64;
  *(_QWORD *)v3->mBoundEffect = -1i64;
  *(_QWORD *)&v3->mBoundEffect[2] = -1i64;
}

// File Line: 126
// RVA: 0x66AD50
void __fastcall UFG::VehicleEffect::VehicleEffect(UFG::VehicleEffect *this, UFG::VehicleEffect *effect)
{
  UFG::VehicleEffect *v2; // rdi
  UFG::VehicleEffect *v3; // rbx
  unsigned int v4; // eax
  Render::FXOverride *v5; // rax
  Render::FXOverride *v6; // rsi

  v2 = effect;
  v3 = this;
  v4 = effect->mName.mUID;
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = v4;
  this->mName.mUID = effect->mName.mUID;
  this->mTransform.mUID = -1;
  this->mMarkerHash.mUID = -1;
  this->mDamageAffectorHash.mUID = -1;
  this->mDamageBoneHash.mUID = -1;
  this->mEffectOverride.m_pPointer = 0i64;
  this->mTransform.mUID = effect->mTransform.mUID;
  this->mMarker = effect->mMarker;
  this->mMarkerHash.mUID = effect->mMarkerHash.mUID;
  this->mDamageBone = effect->mDamageBone;
  this->mDamageBoneHash.mUID = effect->mDamageBoneHash.mUID;
  this->mDamageAffectorBone = effect->mDamageAffectorBone;
  this->mDamageAffectorHash.mUID = effect->mDamageAffectorHash.mUID;
  this->mForwardBone = effect->mForwardBone;
  this->mRearBone = effect->mRearBone;
  this->mEffectRef = -1;
  v5 = this->mEffectOverride.m_pPointer;
  if ( v5 )
  {
    --v5->mReferenceCount;
    v6 = this->mEffectOverride.m_pPointer;
    if ( v6->mReferenceCount <= 0 )
    {
      if ( v6 )
      {
        Render::FXOverride::~FXOverride(this->mEffectOverride.m_pPointer);
        operator delete[](v6);
      }
      v3->mEffectOverride.m_pPointer = 0i64;
    }
    v3->mEffectOverride.m_pPointer = 0i64;
  }
  v3->mDamageMarkerIndex = v2->mDamageMarkerIndex;
  *(_QWORD *)&v3->mRequestedSpeed = 0i64;
  v3->mBoundEffect[0] = v2->mBoundEffect[0];
  v3->mBoundEffect[1] = v2->mBoundEffect[1];
  v3->mBoundEffect[2] = v2->mBoundEffect[2];
  v3->mBoundEffect[3] = v2->mBoundEffect[3];
}

// File Line: 150
// RVA: 0x66DC60
UFG::VehicleEffect *__fastcall UFG::VehicleEffect::operator=(UFG::VehicleEffect *this, UFG::VehicleEffect *rhs)
{
  UFG::VehicleEffect *v2; // rdi
  UFG::VehicleEffect *v3; // rbx
  unsigned int v4; // eax
  Render::FXOverride *v5; // rax
  Render::FXOverride *v6; // rsi

  v2 = rhs;
  v3 = this;
  if ( this != rhs )
  {
    this->mTransform.mUID = rhs->mTransform.mUID;
    this->mMarker = rhs->mMarker;
    this->mMarkerHash.mUID = rhs->mMarkerHash.mUID;
    this->mDamageBone = rhs->mDamageBone;
    this->mDamageBoneHash.mUID = rhs->mDamageBoneHash.mUID;
    this->mDamageAffectorBone = rhs->mDamageAffectorBone;
    this->mDamageAffectorHash.mUID = rhs->mDamageAffectorHash.mUID;
    this->mForwardBone = rhs->mForwardBone;
    v4 = rhs->mRearBone;
    this->mEffectRef = -1;
    this->mRearBone = v4;
    v5 = this->mEffectOverride.m_pPointer;
    if ( v5 )
    {
      --v5->mReferenceCount;
      v6 = this->mEffectOverride.m_pPointer;
      if ( v6->mReferenceCount <= 0 )
      {
        if ( v6 )
        {
          Render::FXOverride::~FXOverride(this->mEffectOverride.m_pPointer);
          operator delete[](v6);
        }
        v3->mEffectOverride.m_pPointer = 0i64;
      }
      v3->mEffectOverride.m_pPointer = 0i64;
    }
    v3->mDamageMarkerIndex = v2->mDamageMarkerIndex;
    v3->mBoundEffect[0] = v2->mBoundEffect[0];
    v3->mBoundEffect[1] = v2->mBoundEffect[1];
    v3->mBoundEffect[2] = v2->mBoundEffect[2];
    v3->mBoundEffect[3] = v2->mBoundEffect[3];
  }
  return v3;
}

// File Line: 208
// RVA: 0x66AF70
void __fastcall UFG::VehicleEffectState::VehicleEffectState(UFG::VehicleEffectState *this, __int64 symbol)
{
  UFG::VehicleEffectState *v2; // rbx
  unsigned int v3; // eax

  v2 = this;
  v3 = *(_DWORD *)symbol;
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = v3;
  this->mStateSymbol.mUID = *(_DWORD *)symbol;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mEffects.mTree);
  v2->mPhantom = 0i64;
}

