// File Line: 12
// RVA: 0xE34F20
void __fastcall hkxMaterialShaderSet::hkxMaterialShaderSet(hkxMaterialShaderSet *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkxMaterialShaderSet::`vftable;
  this->m_shaders.m_capacityAndFlags = 2147483648;
  this->m_shaders.m_data = 0i64;
  this->m_shaders.m_size = 0;
}

// File Line: 16
// RVA: 0xE34F50
void __fastcall hkxMaterialShaderSet::hkxMaterialShaderSet(hkxMaterialShaderSet *this, hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkxMaterialShaderSet::`vftable;
}

