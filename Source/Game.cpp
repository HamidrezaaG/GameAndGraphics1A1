#include "Game.h"


namespace GameDev2D
{
	Game::Game():

        m_TargetPos(GetScreenHeight()*0.5, GetScreenWidth()*0.5)

	{
        MakeCircle();
	}

	Game::~Game()
	{
        UnmakeCircle();
	}

	void Game::Update(double delta)
	{
        if (m_Circle->GetPosition() != m_TargetPos)
        {
            m_Displacement = delta * k_CircleSpeed * (m_TargetPos - m_Circle->GetPosition()).Normalized();

            m_Circle->SetPosition
            (
                m_Circle->GetPosition() + m_Displacement
            );

            if(m_Circle->GetPosition().Distance(m_TargetPos) < k_DistanceThreshold || m_Displacement.DotProduct(m_TargetPos - m_Circle->GetPosition()) < 0)
                m_Circle->SetPosition(m_TargetPos);
        }
	}

	void Game::Draw()
	{
        m_Circle->Draw();
	}

	void Game::HandleLeftMouseClick(float aMouseX, float aMouseY)
	{
        m_TargetPos = GetMousePosition();
	}

	void Game::HandleRightMouseClick(float aMouseX, float aMouseY)
	{

	}

	void Game::HandleMouseMove(float aMouseX, float aMouseY, float aPreviousX, float aPreviousY)
	{
		
	}

	void Game::HandleKeyPress(Keyboard::Key aKey)
	{

	}

	void Game::HandleKeyReleased(Keyboard::Key key)
	{

	}

    void Game::MakeCircle() 
    {
        m_Circle = new Polygon();
        m_Circle->MakeCircle(k_CircleRadius, true);
        m_Circle->SetColor(Color::OrangeColor());
        m_Circle->SetAnchor(0.5f, 0.5f);
        m_Circle->SetPosition(m_TargetPos);
    }

    void Game::UnmakeCircle()
    {
        if (m_Circle != nullptr)
        {
            delete m_Circle;
            m_Circle = nullptr;
        }
    }
}