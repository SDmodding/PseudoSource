// File Line: 16
// RVA: 0xBD4C00
void __fastcall hkaiLocalSteeringInput::init(hkaiLocalSteeringInput *this, hkaiCharacter *character)
{
  this->m_character = character;
  *(_QWORD *)&this->m_distToLocalGoal = 0i64;
  this->m_referenceFrame = 0i64;
  this->m_currentPosition = 0i64;
  this->m_currentForward = 0i64;
  this->m_currentUp = 0i64;
  this->m_currentVelocity = 0i64;
  this->m_desiredVelocity = 0i64;
  this->m_desiredFutureDir = 0i64;
  this->m_localGoalPlane = 0i64;
  this->m_avoidanceProperties = character->m_avoidanceProperties.m_pntr;
  *(_DWORD *)&this->m_isLocalGoalLast.m_bool = 0x1000000;
}

// File Line: 42
// RVA: 0xBD4C50
void __fastcall hkaiLocalSteeringInput::init(
        hkaiLocalSteeringInput *this,
        hkaiCharacter *character,
        hkaiReferenceFrame *referenceFrame,
        hkaiPathFollowingCharacterState *characterState)
{
  hkVector4f v7; // xmm1

  hkaiLocalSteeringInput::init(this, character);
  this->m_currentPosition = characterState->m_position;
  this->m_currentForward = characterState->m_forward;
  this->m_currentUp = characterState->m_up;
  v7.m_quad = (__m128)characterState->m_velocity;
  this->m_referenceFrame = referenceFrame;
  this->m_currentVelocity = (hkVector4f)v7.m_quad;
}

