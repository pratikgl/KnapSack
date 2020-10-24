// function for randomly choosing a set of population

vector<vector<bool>> Populate(vector<int> &w, vector<int> &v, int weight)
{
	// vector of vector<bool>
	// this will store set of population
	vector<vector<bool>> population;

	// the number of objects availbale to choose from
	int n = w.size();

	// In an iteration total number of tries to choose a population
	int pop_count = n;

	for (int i = 0; i < pop_count; i++)
	{
		// will store a temporary population
		vector<bool> P(n, 0);

		// this will store the final weight count of the new randomly chosen population
		int wt_count = 0;

		for (int i = 0; i < n; ++i)
		{
			// by default using probabilty 1/2 to choose an object
			// value will always be either 0 or 1
			int value = rand() % 2;

			// we dont want the wt_count to be greater than the knapsack capacity
			if (value == 1)
			{
				// if the wt_count > knapsack capacity then break
				if (wt_count += w[i] > weight)
				{
					break;
				}
			}

			// if p[i] == 0 (the object has not been chosen)
			// if p[i] == 1 (the object has been chosen)
			P[i] = value;
		}

		// pushing that temporary population in the final population vector
		population.push_back(P);
	}

	return population;
}


// giving the fitness score to the sets of population

int Fitness_Score(vector<bool> &population, vector<int> &value)
{
	int benefit_value = 0;
	for (int i = 0; i < population.size(); ++i)
	{
		if (population[i])
		{
			benefit_value += value[i];
		}
	}

	return benefit_value;
}


// crossing over at a radnomly chosen point

void Crossing_Over(vector<pair<int, vector<bool>>> &v)
{
	int pop_count = v.size() / 2;

	for (int i = 0; i < pop_count; ++i)
	{
		// total number of items
		int n = v[i].second.size();

		// choosing a random point
		int point = rand() % n;

		// crossing over at that random point
		for (int pt = 0; pt <= point; ++pt)
		{
			swap(v[2 * i].second[pt], v[2 * i + 1].second[pt]);
		}
	}
}


// generating mutations in the 10% of the population

void Generate_Mutation(vector<pair<int, vector<bool>>> &v)
{

	for (int i = 0; i < v.size(); ++i)
	{
		// total number of items
		int n = v[0].second.size();

		// number of mutations generated
		// mutating 10 % of the data
		int num = n / 10;
		while (num--)
		{
			// choosing a random point for mutation
			int index = rand() % n;

			// if 0 then 1 (and vice versa)
			v[i].second[index] = !v[i].second[index];
		}
	}
}


// finding the final score of the population

int Final_Score(vector<pair<int, vector<bool>>> &v, vector<int> &w, vector<int> &value, int weight)
{
	int out = -1;

	for (auto it : v)
	{
		int benefit_val = 0;
		int wt = 0;
		int n = it.second.size();

		for (int u = 0; u < n; u++)
		{
			if (it.second[u] == 1)
			{
				if (wt + w[u] > weight)
					break;
				wt += w[u];
				benefit_val += value[u];
			}
		}

		out = max(out, benefit_val);
	}
	return out;
}

// w -> the weight array
// v -> the respective values
// weight -> knpasack capacity
int KnapSack(vector<int> &w, vector<int> &v, int weight)
{
	// total number of the items
	int n = w.size();

	// randomly selected population
	vector<vector<bool>> population = Populate(w, v, weight);

	// adding fitness score
	vector<pair<int, vector<bool>>> benefit;

	for (vector<bool> vec : population)
	{
		int val = Fitness_Score(vec, v);
		benefit.push_back(make_pair(val, vec));
	}

	// sorting accoring to their fitness value
	sort(benefit.begin(), benefit.end(), greater<pair<int, vector<bool>>>());

	// crossing over
	Crossing_Over(benefit);

	// generating random mutations
	Generate_Mutation(benefit);


	// choosing the best benefit score from the given set of population
	int output = Final_Score(benefit, w, v, weight);

	return output;
}