// File Line: 140
// RVA: 0xA6DE00
bool __fastcall CAkParameterNode::ParamOverriden(CAkParameterNode *this, int in_ParamID)
{
  bool v3; // zf

  if ( in_ParamID >= 15 )
  {
    if ( in_ParamID <= 18 )
    {
      v3 = (*((_BYTE *)this + 145) & 0x40) == 0;
    }
    else
    {
      if ( in_ParamID != 19 )
      {
        if ( (unsigned int)(in_ParamID - 22) <= 1 )
          return this->m_pBusOutputNode != 0i64;
        return 0;
      }
      v3 = (*((_BYTE *)this + 145) & 0x10) == 0;
    }
    if ( !v3 || !this->m_pParentNode )
      return 1;
  }
  return 0;
}

// File Line: 167
// RVA: 0xA6DDC0
bool __fastcall CAkParameterNode::ParamMustNotify(CAkParameterNode *this, int in_ParamID)
{
  bool v3; // zf

  if ( in_ParamID >= 15 )
  {
    if ( in_ParamID <= 18 )
    {
      v3 = (*((_BYTE *)this + 145) & 0x40) == 0;
    }
    else
    {
      if ( in_ParamID != 19 )
      {
        if ( (unsigned int)(in_ParamID - 22) <= 1 )
          return this->m_pBusOutputNode != 0i64;
        return 1;
      }
      v3 = (*((_BYTE *)this + 145) & 0x10) == 0;
    }
    if ( v3 && this->m_pParentNode )
      return 0;
  }
  return 1;
}

