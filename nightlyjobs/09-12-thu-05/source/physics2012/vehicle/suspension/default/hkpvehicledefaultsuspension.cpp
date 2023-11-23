// File Line: 15
// RVA: 0xE2ADE0
void __fastcall hkpVehicleDefaultSuspension::calcSuspension(
        hkpVehicleDefaultSuspension *this,
        const float deltaTime,
        hkpVehicleInstance *vehicle,
        hkpVehicleWheelCollide::CollisionDetectionWheelOutput *cdInfo,
        float *suspensionForceOut)
{
  float Mass; // xmm0_4
  hkpVehicleData *m_data; // rbx
  int v10; // r10d
  __int64 v12; // rdx
  __int64 v13; // r11
  float *p_m_currentSuspensionLength; // rcx
  hkpVehicleDefaultSuspension::WheelSpringSuspensionParameters *v15; // r9
  float v16; // xmm2_4
  float m_dampingRelaxation; // xmm1_4

  Mass = hkpMotion::getMass(&vehicle->m_entity->m_motion);
  m_data = vehicle->m_data;
  v10 = 0;
  if ( m_data->m_numWheels > 0 )
  {
    v12 = 0i64;
    v13 = 0i64;
    p_m_currentSuspensionLength = &cdInfo->m_currentSuspensionLength;
    do
    {
      if ( *((_QWORD *)p_m_currentSuspensionLength - 5) )
      {
        v15 = this->m_wheelSpringParams.m_data;
        v16 = p_m_currentSuspensionLength[1];
        if ( v16 >= 0.0 )
          m_dampingRelaxation = v15[v12].m_dampingRelaxation;
        else
          m_dampingRelaxation = v15[v12].m_dampingCompression;
        *suspensionForceOut = (float)((float)((float)((float)(this->m_wheelParams.m_data[v13].m_length
                                                            - *p_m_currentSuspensionLength)
                                                    * v15[v12].m_strength)
                                            * p_m_currentSuspensionLength[2])
                                    - (float)(m_dampingRelaxation * v16))
                            * Mass;
      }
      else
      {
        *suspensionForceOut = 0.0;
      }
      ++v10;
      ++v13;
      p_m_currentSuspensionLength += 24;
      ++v12;
      ++suspensionForceOut;
    }
    while ( v10 < m_data->m_numWheels );
  }
}

