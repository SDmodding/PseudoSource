// File Line: 13
// RVA: 0x272A10
void __fastcall ITask::SetTrack(ITask *this, ITrack *track)
{
  this->m_Track = track;
  if ( track )
  {
    this->m_TimeBegin = track->mTimeBegin;
    this->m_TimeEnd = track->mTimeEnd;
  }
}

