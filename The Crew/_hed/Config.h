//
// Purpur Tentakel
// 12.07.2022
//

#pragma once
enum class PlayerCountValue {
	THREE = 3,
	FOUR,
	FIVE
};

struct PlayerCount {
private:
	PlayerCountValue playerCount;
	PlayerCount();
	PlayerCount(const PlayerCount& old) = delete;
public:
	[[nodiscard]] static PlayerCount& GetInstance();
	[[nodiscard]] PlayerCountValue GetPlayerCount() const;
	bool SetPlayerCount(int input);
	void SetPlayerCountWithInput();
};





