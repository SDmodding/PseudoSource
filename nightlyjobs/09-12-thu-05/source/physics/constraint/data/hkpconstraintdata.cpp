// File Line: 16
// RVA: 0xD44FF0
void __fastcall hkpConstraintData::hkpConstraintData(hkpConstraintData *this, hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkpConstraintData::`vftable';
}

// File Line: 23
// RVA: 0xD450D0
void __fastcall hkpConstraintData::addInstance(hkpConstraintData *this, struct hkpConstraintRuntime *runtime, int sizeOfRuntime)
{
  if ( runtime )
    hkString::memSet((void *)runtime, 0, sizeOfRuntime);
}

// File Line: 31
// RVA: 0xD450C0
hkpSolverResults *__fastcall hkpConstraintData::getSolverResults(hkpConstraintData *this, struct hkpConstraintRuntime *runtime)
{
  return (hkpSolverResults *)runtime;
}

// File Line: 58
// RVA: 0xD45110
void __fastcall hkpConstraintData::getConstraintInfoUtil(hkpConstraintAtom *atoms, int sizeOfAllAtoms, hkpConstraintData::ConstraintInfo *infoOut)
{
  unsigned __int16 *v3; // r9
  hkpConstraintAtom *v4; // r10
  unsigned int v5; // eax
  int v6; // ecx
  int v7; // ecx

  v3 = &atoms->m_type.m_storage;
  v4 = (hkpConstraintAtom *)((char *)atoms + sizeOfAllAtoms);
  infoOut->m_atoms = atoms;
  infoOut->m_sizeOfAllAtoms = sizeOfAllAtoms;
  infoOut->m_maxSizeOfSchema = 0;
  *(_QWORD *)&infoOut->m_numSolverResults = 0i64;
  infoOut->m_sizeOfSchemas = 32;
  if ( atoms < v4 )
  {
    do
    {
      v5 = *v3;
      while ( 2 )
      {
        switch ( v5 )
        {
          case 0u:
            v3 = (unsigned __int16 *)(((unsigned __int64)v3 + 15) & 0xFFFFFFFFFFFFFFF0ui64);
            v5 = *v3;
            if ( v5 <= 0x22 )
              continue;
            goto LABEL_13;
          case 1u:
          case 0x1Eu:
          case 0x1Fu:
          case 0x20u:
          case 0x21u:
          case 0x22u:
            return;
          case 2u:
            v3 += 72;
            goto LABEL_13;
          case 3u:
            goto $LN4_181;
          case 4u:
            v3 += 56;
            goto LABEL_13;
          case 5u:
            infoOut->m_sizeOfSchemas += 144;
            infoOut->m_numSolverResults += 3;
            infoOut->m_numSolverElemTemps += 3;
            infoOut->m_extraSchemaSize -= 16;
            goto $LN3_166;
          case 6u:
            infoOut->m_sizeOfSchemas += 48;
            ++infoOut->m_numSolverResults;
            ++infoOut->m_numSolverElemTemps;
            infoOut->m_extraSchemaSize += 64;
            v3 += 6;
            goto LABEL_13;
          case 7u:
          case 0xEu:
            infoOut->m_sizeOfSchemas += 48;
            goto LABEL_11;
          case 8u:
          case 9u:
          case 0x15u:
          case 0x16u:
            infoOut->m_sizeOfSchemas += 64;
LABEL_11:
            ++infoOut->m_numSolverResults;
            ++infoOut->m_numSolverElemTemps;
            goto $LN3_166;
          case 0xAu:
          case 0xCu:
            infoOut->m_sizeOfSchemas += 64;
            infoOut->m_numSolverResults += 2;
            infoOut->m_numSolverElemTemps += 2;
            goto $LN3_166;
          case 0xBu:
            infoOut->m_sizeOfSchemas += 80;
            infoOut->m_numSolverResults += 2;
            infoOut->m_numSolverElemTemps += 2;
            v3 += 12;
            goto LABEL_13;
          case 0xDu:
            v6 = *((unsigned __int8 *)v3 + 3);
            infoOut->m_numSolverResults += v6;
            infoOut->m_sizeOfSchemas += 32 * v6;
            infoOut->m_numSolverElemTemps += v6;
            goto $LN3_166;
          case 0xFu:
          case 0x10u:
            infoOut->m_sizeOfSchemas += 48;
            ++infoOut->m_numSolverResults;
            ++infoOut->m_numSolverElemTemps;
            v3 += 16;
            goto LABEL_13;
          case 0x11u:
            v7 = *((unsigned __int8 *)v3 + 4);
            infoOut->m_sizeOfSchemas += 48 * v7;
            infoOut->m_numSolverResults += 2 * v7;
            infoOut->m_numSolverElemTemps += 2 * v7;
            goto $LN3_166;
          case 0x12u:
            infoOut->m_sizeOfSchemas += 64;
            infoOut->m_numSolverResults += 2;
            infoOut->m_numSolverElemTemps += 2;
            v3 += 20;
            goto LABEL_13;
          case 0x13u:
            infoOut->m_sizeOfSchemas += 192;
            infoOut->m_numSolverResults += 6;
            infoOut->m_numSolverElemTemps += 6;
            v3 += 48;
            goto LABEL_13;
          case 0x14u:
            infoOut->m_sizeOfSchemas += 64;
            ++infoOut->m_numSolverResults;
            ++infoOut->m_numSolverElemTemps;
            v3 += 32;
            goto LABEL_13;
          case 0x17u:
            goto $LN3_166;
          case 0x18u:
            infoOut->m_sizeOfSchemas += 48;
            infoOut->m_numSolverResults += 3;
            infoOut->m_numSolverElemTemps += 3;
            infoOut->m_extraSchemaSize += 64;
$LN3_166:
            v3 += 8;
            break;
          case 0x19u:
          case 0x1Au:
            infoOut->m_sizeOfSchemas += 128;
            infoOut->m_numSolverResults += 3;
            infoOut->m_numSolverElemTemps += 3;
            infoOut->m_extraSchemaSize += 64;
            v3 += 48;
            break;
          case 0x1Cu:
            infoOut->m_sizeOfSchemas += 112;
            infoOut->m_numSolverElemTemps += 2;
$LN4_181:
            v3 += 24;
            break;
          default:
            goto LABEL_13;
        }
        break;
      }
LABEL_13:
      ;
    }
    while ( v3 < (unsigned __int16 *)v4 );
  }
}

// File Line: 187
// RVA: 0xD45010
void __fastcall hkpConstraintData::setMaximumLinearImpulse(hkpConstraintData *this, float maxLinearImpulse)
{
  ;
}

// File Line: 192
// RVA: 0xD45020
void __fastcall hkpConstraintData::setMaximumAngularImpulse(hkpConstraintData *this, float maxAngularImpulse)
{
  ;
}

// File Line: 197
// RVA: 0xD45030
void __fastcall hkpConstraintData::setBreachImpulse(hkpConstraintData *this, float breachImpulse)
{
  ;
}

// File Line: 202
// RVA: 0xD45040
float __fastcall hkpConstraintData::getMaximumLinearImpulse(hkpConstraintData *this)
{
  return FLOAT_3_40282e38;
}

// File Line: 207
// RVA: 0xD45050
float __fastcall hkpConstraintData::getMaximumAngularImpulse(hkpConstraintData *this)
{
  return FLOAT_3_40282e38;
}

// File Line: 212
// RVA: 0xD45060
float __fastcall hkpConstraintData::getBreachImpulse(hkpConstraintData *this)
{
  return FLOAT_3_40282e38;
}

// File Line: 217
// RVA: 0xD45080
char __fastcall hkpConstraintData::getNotifiedBodyIndex(hkpConstraintData *this)
{
  return -1;
}

// File Line: 223
// RVA: 0xD45070
void __fastcall hkpConstraintData::setBodyToNotify(hkpConstraintData *this, int bodyIdx)
{
  ;
}

// File Line: 228
// RVA: 0xD45090
void __fastcall hkpConstraintData::setSolvingMethod(hkpConstraintData *this, hkpConstraintAtom::SolvingMethod method)
{
  ;
}

// File Line: 233
// RVA: 0xD450A0
hkResult *__fastcall hkpConstraintData::setInertiaStabilizationFactor(hkpConstraintData *this, hkResult *result, const float inertiaStabilizationFactor)
{
  result->m_enum = 1;
  return result;
}

// File Line: 238
// RVA: 0xD450B0
hkResult *__fastcall hkpConstraintData::getInertiaStabilizationFactor(hkpConstraintData *this, hkResult *result, float *inertiaStabilizationFactorOut)
{
  result->m_enum = 1;
  return result;
}

// File Line: 243
// RVA: 0xD450F0
void __fastcall hkpConstraintData::buildJacobian(hkpConstraintData *this, hkpConstraintQueryIn *in, hkpConstraintQueryOut *out)
{
  ;
}

// File Line: 248
// RVA: 0xD45100
void __fastcall hkpConstraintData::buildJacobianCallback(hkpConstraintData *this, hkpConstraintQueryIn *in, hkpConstraintQueryOut *out)
{
  ;
}

