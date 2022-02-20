#pragma once
class CEntity {
public:
	const int& getHealth() const noexcept
	{
		return *reinterpret_cast<int*>(std::uintptr_t(this) + m_iHealth);
	}
	const int& getTeam() const noexcept
	{
		return *reinterpret_cast<int*>(std::uintptr_t(this) + m_iTeamNum);
	}
	const int& getTickBase() const noexcept
	{
		return *reinterpret_cast<int*>(std::uintptr_t(this) + m_nTickBase);
	}
	const float& getFlashMaxAlpha() const noexcept
	{
		return *reinterpret_cast<float*>(std::uintptr_t(this) + m_flFlashMaxAlpha);
	}
	const int& getFlags() const noexcept
	{
		return *reinterpret_cast<int*>(std::uintptr_t(this) + m_fFlags);
	}
	const int& getLifeState() const noexcept
	{
		return *reinterpret_cast<int*>(std::uintptr_t(this) + m_lifeState);
	}
	const int& getGlowIndex() const noexcept
	{
		return *reinterpret_cast<int*>(std::uintptr_t(this) + m_iGlowIndex);
	}
	const bool& getZoom() const noexcept
	{
		return *reinterpret_cast<bool*>(std::uintptr_t(this) + m_bIsScoped);
	}
	const float& getFlashed() const noexcept
	{
		return *reinterpret_cast<float*>(std::uintptr_t(this) + m_flFlashDuration);
	}
	const bool& getDormant() const noexcept
	{
		return *reinterpret_cast<bool*>(std::uintptr_t(this) + m_bDormant);
	}
};
