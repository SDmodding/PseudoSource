// File Line: 15
// RVA: 0xE2ADE0
void __fastcall hkpVehicleDefaultSuspension::calcSuspension(hkpVehicleDefaultSuspension *this, const float deltaTime, hkpVehicleInstance *vehicle, hkpVehicleWheelCollide::CollisionDetectionWheelOutput *cdInfo, float *suspensionForceOut)
{
  hkpVehicleDefaultSuspension *v5; // rsi
  hkpVehicleWheelCollide::CollisionDetectionWheelOutput *v6; // rdi
  hkpVehicleInstance *v7; // rbx
  float v8; // xmm0_4
  hkpVehicleData *v9; // rbx
  signed int v10; // er10
  float *v11; // r8
  __int64 v12; // rdx
  __int64 v13; // r11
  float *v14; // rcx
  hkpVehicleDefaultSuspension::WheelSpringSuspensionParameters *v15; // r9
  float v16; // xmm2_4
  float v17; // xmm1_4

  v5 = this;
  v6 = cdInfo;
  v7 = vehicle;
  v8 = hkpMotion::getMass((hkpMotion *)&vehicle->m_entity->m_motion.vfptr);
  v9 = v7->m_data;
  v10 = 0;
  if ( v9->m_numWheels > 0 )
  {
    v11 = suspensionForceOut;
    v12 = 0i64;
    v13 = 0i64;
    v14 = &v6->m_currentSuspensionLength;
    do
    {
      if ( *((_QWORD *)v14 - 5) )
      {
        v15 = v5->m_wheelSpringParams.m_data;
        v16 = v14[1];
        if ( v16 >= 0.0 )
          v17 = v15[v12].m_dampingRelaxation;
        else
          v17 = v15[v12].m_dampingCompression;
        *v11 = (float)((float)((float)((float)(v5->m_wheelParams.m_data[v13].m_length - *v14) * v15[v12].m_strength)
                             * v14[2])
                     - (float)(v17 * v16))
             * v8;
      }
      else
      {
        *v11 = 0.0;
      }
      ++v10;
      ++v13;
      v14 += 24;
      ++v12;
      ++v11;
    }
    while ( v10 < v9->m_numWheels );
  }
}

