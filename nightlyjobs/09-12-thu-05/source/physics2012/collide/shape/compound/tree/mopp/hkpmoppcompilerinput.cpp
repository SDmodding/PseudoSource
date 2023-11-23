// File Line: 13
// RVA: 0xD34E60
void __fastcall hkpMoppCompilerInput::hkpMoppCompilerInput(hkpMoppCompilerInput *this)
{
  this->m_absoluteFitToleranceOfTriangles = 0.30000001;
  this->m_relativeFitToleranceOfInternalNodes = 0.40000001;
  this->m_absoluteFitToleranceOfInternalNodes = 0.1;
  this->m_absoluteFitToleranceOfAxisAlignedTriangles = (hkVector4f)_xmm;
  *(_WORD *)&this->m_useShapeKeys.m_bool = 257;
  *(_WORD *)&this->m_enableInterleavedBuilding.m_bool = 1;
  this->m_enableChunkSubdivision.m_bool = 0;
}

// File Line: 26
// RVA: 0xD34EA0
void __fastcall hkpMoppCompilerInput::setAbsoluteFitToleranceOfTriangles(hkpMoppCompilerInput *this, float inTight)
{
  this->m_absoluteFitToleranceOfTriangles = inTight;
}

// File Line: 31
// RVA: 0xD34EB0
float __fastcall hkpMoppCompilerInput::getAbsoluteFitToleranceOfTriangles(hkpMoppCompilerInput *this)
{
  return this->m_absoluteFitToleranceOfTriangles;
}

// File Line: 36
// RVA: 0xD34EC0
void __fastcall hkpMoppCompilerInput::setAbsoluteFitToleranceOfAxisAlignedTriangles(
        hkpMoppCompilerInput *this,
        hkVector4f *inTight)
{
  this->m_absoluteFitToleranceOfAxisAlignedTriangles = (hkVector4f)inTight->m_quad;
}

// File Line: 41
// RVA: 0xD34ED0
hkVector4f *__fastcall hkpMoppCompilerInput::getAbsoluteFitToleranceOfAxisAlignedTriangles(
        hkpMoppCompilerInput *this,
        hkVector4f *result)
{
  hkVector4f *v2; // rax

  v2 = result;
  *result = this->m_absoluteFitToleranceOfAxisAlignedTriangles;
  return v2;
}

// File Line: 46
// RVA: 0xD34EF0
void __fastcall hkpMoppCompilerInput::setRelativeFitToleranceOfInternalNodes(
        hkpMoppCompilerInput *this,
        float inUnused)
{
  this->m_relativeFitToleranceOfInternalNodes = inUnused;
}

// File Line: 51
// RVA: 0xD34F00
float __fastcall hkpMoppCompilerInput::getRelativeFitToleranceOfInternalNodes(hkpMoppCompilerInput *this)
{
  return this->m_relativeFitToleranceOfInternalNodes;
}

// File Line: 56
// RVA: 0xD34F10
void __fastcall hkpMoppCompilerInput::setAbsoluteFitToleranceOfInternalNodes(hkpMoppCompilerInput *this, float inMin)
{
  this->m_absoluteFitToleranceOfInternalNodes = inMin;
}

// File Line: 61
// RVA: 0xD34F20
float __fastcall hkpMoppCompilerInput::getAbsoluteFitToleranceOfInternalNodes(hkpMoppCompilerInput *this)
{
  return this->m_absoluteFitToleranceOfInternalNodes;
}

