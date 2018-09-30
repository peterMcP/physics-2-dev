#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleSceneIntro.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModulePhysics.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	circle = box = rick = NULL;
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->renderer->camera.x = App->renderer->camera.y = 0;

	circle = App->textures->Load("pinball/wheel.png"); 
	box = App->textures->Load("pinball/crate.png");
	rick = App->textures->Load("pinball/rick_head.png");

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	circleList.clear();
	boxList.clear();
	chainList.clear();

	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	// TODO 4: Move all creation of bodies on 1,2,3 key press here in the scene
	// On space bar press, create a circle on mouse position
	if (App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN)
	{
		PhysBody* body = App->physics->createCircle(25);
		circleList.add(body);
	}

	if (App->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN)
	{
		// TODO 1: When pressing 2, create a box on the mouse position
		// To have the box behave normally, set fixture's density to 1.0f

		PhysBody* body = App->physics->createBox(50.0f, 25.0f);
		boxList.add(body);
	}

	if (App->input->GetKey(SDL_SCANCODE_3) == KEY_DOWN)
	{
		// TODO 2: Create a chain shape using those vertices
		// remember to convert them from pixels to meters!


		PhysBody* body = App->physics->createChain(App->physics->rick_head, 40);
		chainList.add(body);

	}
	
	// TODO 6: Draw all the circles using "circle" texture

	// circles draw

	p2List_item<PhysBody*>* item = circleList.getFirst();

	while (item != NULL)
	{
		App->renderer->Blit(circle, METERS_TO_PIXELS(item->data->GetPosition().x) - 25, METERS_TO_PIXELS(item->data->GetPosition().y) - 25,
							NULL, 1.0f, item->data->GetRotation());

		item = item->next;
	}
	// box draw

	item = boxList.getFirst();

	while (item != NULL)
	{
		App->renderer->Blit(box, METERS_TO_PIXELS(item->data->GetPosition().x) - 50, METERS_TO_PIXELS(item->data->GetPosition().y) - 25,
			NULL, 1.0f, item->data->GetRotation());

		item = item->next;
	}

	item = chainList.getFirst();

	while (item != NULL)
	{
		App->renderer->Blit(rick, METERS_TO_PIXELS(item->data->GetPosition().x), METERS_TO_PIXELS(item->data->GetPosition().y),
			NULL, 1.0f, item->data->GetRotation());

		item = item->next;
	}


	return UPDATE_CONTINUE;
}
