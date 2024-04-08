from constants import (MOVIE_TSV_PATH,
                       ACTOR_TSV_PATH,
                       MOVIE_BIN_PATH,
                       ACTOR_BIN_PATH)
import pandas as pd
import msgpack


def to_utf8(value):
    return str(value).encode('utf-8', 'ignore').decode('utf-8', 'ignore')


if __name__ == "__main__":
    # title_data = pd.read_csv(MOVIE_TSV_PATH, sep='\t')
    # titles = []
    # for index, title in title_data.iterrows():
    #     if title['titleType'].strip() == 'movie':
    #         cleaned_title = to_utf8(title['primaryTitle'])
    #         titles.append([to_utf8(title['tconst']), cleaned_title])
    # titles_bin = msgpack.packb(titles)
    # with open(MOVIE_BIN_PATH, 'wb+') as f:
    #     f.write(titles_bin)

    actor_data = pd.read_csv(ACTOR_TSV_PATH, sep='\t')
    actors = []
    for index, actor in actor_data.iterrows():
        if 'actor' not in actor['primaryProfession']:
            continue
        cleaned_name = to_utf8(actor['primaryName'])
        cleaned_titles = [to_utf8(t)
                          for t in actor['knownForTitles'].split(',')]
        actors.append([to_utf8(actor['nconst']), cleaned_name, cleaned_titles])
    actor_bin = msgpack.packb(actors)
    with open(ACTOR_BIN_PATH, 'wb+') as f:
        f.write(actor_bin)

    print(f'NUMBER UNIQUE ACTORS: {len(actors)}')
